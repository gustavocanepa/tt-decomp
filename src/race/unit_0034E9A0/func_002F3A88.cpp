/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Builds the engine's torque and power curve: the rpm points of the engine
   table rounded to 100 rpm, and the peak torque and power with their rpm. */
typedef signed short s16;
typedef unsigned short u16;
typedef float f32;

struct Params;

struct Engine {
    s16 count;           /* 0x00 */
    char pad02[0xC - 2];
    f32 speeds[0x30];    /* 0x0C: rad/s */
    u16 rev_limit;       /* 0xCC */
};

struct EngineCurve {
    f32 max_power;       /* 0x00 */
    f32 max_torque;      /* 0x04 */
    s16 power_rpm;       /* 0x08 */
    s16 torque_rpm;      /* 0x0A */
    u16 rev_limit;       /* 0x0C */
    s16 count;           /* 0x0E */
    s16 rpm[0x18];       /* 0x10 */
    f32 power[0x18];     /* 0x40 */
    f32 torque[0x18];    /* 0xA0 */
};

extern "C" f32 func_002F3030(void *engine, Params *p, f32 w) throw();
extern "C" f32 func_002F30F8(void *engine, f32 load, f32 w) throw();

/* Fills an EngineCurve from the engine table: the rpm grid rounded to 100 rpm taken from
   engine->speeds, then torque/power samples per 100 rpm up to highest rpm wanted, keeping
   the peaks with their rpm and storing them last (store order is scheduler-imposed).
   The init chain max_power=0 / max_torque=max_power after the rpm counters keeps the
   FP callee-saved register order aligned with the tail store emission. */

extern "C" void func_002F3A88(Engine *engine, EngineCurve *curve, Params *p)
{
    int n = 0;
    int rpm;
    int i;
    f32 max_power = 0.0f;
    int torque_rpm = 0;
    int power_rpm = 0;
    f32 max_torque = max_power;

    for (i = 0; i < engine->count; i++) {
        rpm = (int)(engine->speeds[i] * 60.0f / 0x1.921fb4p+2f);
        rpm = (rpm + 50) / 100 * 100;
        if (n <= 0 || curve->rpm[n - 1] < rpm) {
            curve->rpm[n] = rpm;
            n++;
        }
    }
    curve->count = n;

    rpm = curve->rpm[0];
    int top = curve->rev_limit = engine->rev_limit;
    int end = curve->rpm[n - 1];
    if (top < end)
        top = end;
    int k = 0;
    for (; rpm <= top; rpm += 100) {
        f32 r = (f32)rpm;
        f32 omega = r * 0x1.acee9cp-4f;
        f32 torque = func_002F30F8(engine, func_002F3030(engine, p, omega), omega) / 9.8f;
        f32 power = torque * r / 0x1.661998p+9f;
        if (curve->rpm[k] == rpm) {
            curve->power[k] = power;
            curve->torque[k] = torque;
            k++;
        }
        if (curve->rev_limit < rpm)
            continue;
        if (max_torque < torque) {
            max_torque = torque;
            torque_rpm = rpm;
        }
        if (max_power < power) {
            max_power = power;
            power_rpm = rpm;
        }
    }
    if (curve != 0) {
        curve->max_power = max_power;
        curve->power_rpm = power_rpm;
        curve->max_torque = max_torque;
        curve->torque_rpm = torque_rpm;
    }
}
