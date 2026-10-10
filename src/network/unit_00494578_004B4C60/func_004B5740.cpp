/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Mutex { int w[2]; };
struct State { int event[12]; char a, b, c, d, e, f, g, h, i; char pad39[0x144 - 0x39]; f32 value[3]; };
extern "C" Mutex D_00773E68;
extern "C" State D_00773E70;
extern "C" void func_004A4930(Mutex *m);
extern "C" void func_004A4970(Mutex *m);
extern "C" void func_004AEB30(void *event);

struct ScopedLock {
    Mutex *m;
    ScopedLock(Mutex *mutex) : m(mutex) { func_004A4930(m); }
    ~ScopedLock() { func_004A4970(m); }
};

extern "C" void func_004B5740(f32 value)
{
    {
        ScopedLock lock(&D_00773E68);
        D_00773E70.a = 1;
        D_00773E70.g = 1;
        D_00773E70.value[0] = value;
    }
    func_004AEB30(D_00773E70.event);
}
