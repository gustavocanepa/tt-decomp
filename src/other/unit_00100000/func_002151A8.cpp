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

extern "C" void func_0043A7E8(void *);
extern "C" void func_00439930(void *);
extern "C" void func_0043AD60(s32, void *);
extern "C" s32 func_0050E018(s32);
extern "C" void func_00447B18(s32, s32);
extern "C" void func_0043BB88(s32, s32, s32, s32);

extern "C" void func_002151A8(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 v_s0;
    *(s32 *)((char *)arg0 + 0xc) = (s32)arg1;
    func_0043A7E8(arg1);
    func_00439930(buf0);
    func_0043AD60(*(s32 *)((char *)arg0 + 0xc), buf0);
    *(s32 *)((char *)arg0 + 0x18) = arg2;
    if (*(s32 *)((char *)arg0 + 0x1c) != 0) {
        v_s0 = func_0050E018(0x14);
        func_00447B18(v_s0, 0x4000);
        *(s32 *)((char *)arg0 + 0x14) = v_s0;
        v_s0 = func_0050E018(0x19c);
        func_0043BB88(v_s0, *(s32 *)((char *)arg0 + 0xc), 0, *(s32 *)((char *)arg0 + 0x14));
        *(s32 *)((char *)arg0 + 0x10) = v_s0;
        *(s32 *)((char *)v_s0 + 0x10) = 0;
    }
}
