/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

struct Slot { char pad[0x6E4]; f32 a; f32 b; };
struct Ev { char pad[0xDC]; s32 f; };

extern "C" Slot *func_002F04D8(void *arg0, s32 arg1);
extern "C" void func_002E4EF0(void *p, s32 n);
extern "C" s32 DynamicsConductorMachineTest__getTestMode(void *p) throw();
extern "C" s32 func_002FBE58(void *self, s32 a, u32 b);
extern "C" void func_00305DD8(void *self, s32 v, s32 w, s32 x, s32 t, s32 f);
extern "C" void func_00306050(void *self, s32 a, f32 c, u8 b);
extern "C" void func_003052F0(void *p, s32 a, s32 b, s32 c);

extern "C" s32 func_003A4230(Ev **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    Slot *s0 = func_002F04D8(arg0, arg1);
    Ev *ev = *arg0;
    char *q = (char *)s0 + 0x104;
    s32 m;
    if (s0->b < s0->a) {
        s0->b = s0->a;
    }
    if (ev->f != 0) {
        return 0;
    }
    func_002E4EF0(s0, 1);
    if (*(u8 *)(q + 0x461) == 0 && *(u8 *)((char *)arg0 + 0x20A24) == 0) {
        m = DynamicsConductorMachineTest__getTestMode(arg0);
        if (m < 3) {
            if (m > 0) {
                func_002FBE58(arg0, arg1, arg5);
            }
        }
    }
    m = DynamicsConductorMachineTest__getTestMode(arg0);
    switch (m) {
    case 1:
    case 2:
        func_00305DD8(arg0, arg1, arg2, arg4, arg5, *(u8 *)((char *)s0 + 0x5D7));
        break;
    case 0:
    case 3:
        func_00306050(arg0, arg1, s0->b, *(u8 *)((char *)s0 + 0x5D7));
        break;
    }
    if (arg1 == 0) {
        func_003052F0(*arg0, 5, 0, 2);
    }
    return 1;
}
