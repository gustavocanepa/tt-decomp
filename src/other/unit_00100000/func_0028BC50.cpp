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

extern "C" void * func_0028B8B0(void *);
extern "C" void * func_0029B4E0(void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029B488(void *, s32);
extern "C" void func_0028B858(void *, s32);

extern "C" void func_0028BC50(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 v_s1;
    s32 v_s0;
    if (arg2 > 0) {
        func_0028B8B0(buf0);
        p_s2 = buf1;
        func_0029B4E0(p_s2, arg3);
        v_s1 = buf0[0] + 0xB4;
        if ((char *)v_s1 != (char *)p_s2) {
            v_s0 = *p_s2;
            if (v_s0 != 0) {
                func_002C0FE8(v_s0);
            }
            if (*(s32 *)(char *)v_s1 != 0) {
                func_002C1050(*(s32 *)(char *)v_s1);
            }
            *(s32 *)(char *)v_s1 = v_s0;
        }
        func_0029B488(p_s2, 0x2);
        func_0028B858(buf0, 0x2);
    }
}
