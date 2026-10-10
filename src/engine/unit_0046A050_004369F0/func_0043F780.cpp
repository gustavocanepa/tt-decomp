typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" s32 func_00445370(void *, void *);
extern "C" void func_00439EC8(s32, s32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_00478C98(s32);
extern "C" void func_0043A298(s32, void *);
extern "C" void func_00473178(s32);
extern "C" void func_0047525C(s32);

extern "C" void func_0043F780(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 v_s0;
    if (*(s32 *)((char *)arg0 + 0x6e38) == 0) {
        buf0[0] = 0x80ffffff;
        func_00439EC8(*(s32 *)((char *)arg0 + 0x6e14), func_00445370((char *)arg0 + 0x6e18, buf0));
    }
    v_s0 = *(s32 *)((char *)arg0 + 0x6e14);
    func_0046F0F8(0x2);
    func_00478C98(0x9);
    *(s32 *)((char *)v_s0 + 0x4) = 0x1;
    if (arg1 != 0) {
        func_0043A298(*(s32 *)((char *)arg0 + 0x6e14), arg1);
    }
    func_00473178(0x2);
    func_0047525C(arg2);
    func_00473178(0);
}
