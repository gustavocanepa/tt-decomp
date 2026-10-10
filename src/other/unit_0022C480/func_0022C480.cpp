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

extern "C" void func_002ADC48(void *, void *);
extern "C" void func_0022C140(void *, void *);
extern "C" s32 func_002AFE68(s32);
extern "C" void func_0022CEE8(void *, s32, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0022E3E8(void *, s32);
extern "C" void func_0022C0E8(void *, s32);
extern "C" void func_002ADBF0(void *, s32);

extern "C" void func_0022C480(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s3;
    s32 *p_s2;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    func_002ADC48(buf0, arg3);
    p_s3 = buf2;
    p_s2 = buf1;
    if (buf0[0] != 0) {
        func_0022C140(p_s3, arg1);
        v_s0 = *p_s3;
        func_0022CEE8(p_s2, v_s0, func_002AFE68(buf0[0]));
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
        func_0022E3E8(p_s2, 0x2);
        func_0022C0E8(p_s3, 0x2);
    }
    func_002ADBF0(buf0, 0x2);
}
