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

extern "C" void func_0029EA18(void *, s32);
extern "C" void func_001C04F8(void *, void *, s32, void *, s32);
extern "C" void func_001E4E80(void *, void *);
extern "C" void func_001C0228(void *, s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void func_0017DD58(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    char *v_s2;
    s32 *p_s0;
    v_s2 = (char *)arg0 + 0x100;
    if (*(s32 *)(char *)v_s2 != 0) {
        func_0029EA18(buf0, arg2 != 0);
        p_s0 = buf1;
        func_001C04F8(p_s0, v_s2, 0x2, arg1, buf0[0]);
        func_001E4E80(arg1, p_s0);
        func_001C0228(p_s0, 0x2);
        func_0029CEF0(buf0, 0x2);
    }
}
