/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Ent { char pad0[4]; s32 f4; char pad8[0x24]; s32 f2C; char pad30[0xC]; };
struct Group { char pad[0x78]; s32 cur; };
struct T {
    char pad0[0x34]; s32 f2C; char pad30[0xC];
};

extern "C" void func_001049E0(void *, s32);
extern "C" void func_00104A48(void *, s32, s32);
extern "C" void func_00104A88(void *, s32);
extern "C" void func_00105778(T *, s32, s32, s32);
extern "C" void func_00105860(T *, s32, s32);
extern "C" void func_004780D0(void);
extern "C" s32 func_004781C8(s32, s32);

#define E(g, k) ((Ent *)((char *)(g) + (k) * 0x3C))

extern "C" void func_00106070(char *arg0, u32 arg1, s32 arg2, s32 arg3) {
    Group *g0 = (Group *)(arg0 + 0x44);
    Group *g1 = (Group *)(arg0 + 0xC0);
    s32 half;
    s32 buf;
    func_004780D0();
    func_00105778((T *)arg0, 1, 2, 0);
    func_00105860((T *)arg0, arg2, arg3);
    g0->cur = 0;
    s32 mul;
    if (arg1 < 2U) mul = 2; else mul = 1;
    half = arg2 * arg3 * mul / 2;
    buf = func_004781C8(half * 2, 0);
    *(s32 *)(arg0 + 0x178) = buf;
    func_001049E0(E(g0, g0->cur), buf);
    { Ent *e = E(g0, g0->cur); e->f4 = arg1; }
    func_00104A48(E(g0, g0->cur), arg2, arg3);
    func_00104A88(E(g0, g0->cur), 1);
    { Ent *e = E(g0, g0->cur); e->f2C = 0; }
    func_001049E0(E(g0, (1 - g0->cur)), buf + half);
    { Ent *e = E(g0, (1 - g0->cur)); e->f4 = arg1; }
    func_00104A48(E(g0, (1 - g0->cur)), arg2, arg3);
    func_00104A88(E(g0, (1 - g0->cur)), 1);
    { Ent *e = E(g0, (1 - g0->cur)); e->f2C = 0; }
    func_001049E0(E(g1, g1->cur), buf);
    { Ent *e = E(g1, g1->cur); e->f4 = 0x31; }
    func_00104A48(E(g1, g1->cur), arg2, arg3);
    func_00104A88(E(g1, g1->cur), 9);
    { Ent *e = E(g1, g1->cur); e->f2C = 0; }
    func_001049E0(E(g1, (1 - g1->cur)), buf + 0x46000);
    { Ent *e = E(g1, (1 - g1->cur)); e->f4 = 0x31; }
    func_00104A48(E(g1, (1 - g1->cur)), arg2, arg3);
    func_00104A88(E(g1, (1 - g1->cur)), 9);
    { Ent *e = E(g1, (1 - g1->cur)); e->f2C = 0; }
    func_001049E0(arg0 + 0x13C, -1);
    ((T *)arg0)->f2C = arg1;
}
