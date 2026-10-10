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

extern "C" void func_00296A78(void *, void *);
extern "C" s32 func_00297730(s32);
extern "C" s32 func_002A8968(s32, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_00296A20(void *, s32);

extern "C" void func_002A7EC0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s1;
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_00296A78(buf0, arg3);
    v_s1 = *(s32 *)(char *)arg1;
    t1 = func_002A8968(v_s1, func_00297730(buf0[0]));
    p_s1 = buf1;
    func_0029EA18(p_s1, t1 != 0);
    if (arg0 != p_s1) {
        newVal = *p_s1;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(p_s1, 0x2);
    func_00296A20(buf0, 0x2);
}
