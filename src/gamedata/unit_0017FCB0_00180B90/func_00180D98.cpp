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

extern "C" void func_001803E8(void *);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_00182E78(s32, s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_00180390(void *, s32);

extern "C" void func_00180D98(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s1;
    s32 v_s0;
    func_001803E8(buf0);
    p_s1 = buf2;
    v_s0 = buf0[0];
    func_0029CF48(p_s1, arg3);
    func_00182E78(v_s0, func_0029E9F0(*p_s1));
    func_0029CEF0(p_s1, 0x2);
    func_00180390(buf0, 0x2);
}
