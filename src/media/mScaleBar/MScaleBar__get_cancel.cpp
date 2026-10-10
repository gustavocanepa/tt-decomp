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

extern "C" void * func_001E9E98(void *);
extern "C" void * func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_001E9E40(void *, s32);

extern "C" void MScaleBar__get_cancel(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 0) {
        func_001E9E98(buf0);
        p_s2 = buf1;
        func_0029EA18(p_s2, *(s32 *)((char *)buf0[0] + 0x100) != 0);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(p_s2, 0x2);
        func_001E9E40(buf0, 0x2);
    }
}
