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
extern "C" void func_001DF250(void *, void *);
extern "C" s32 func_00183D70(s32, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_00180390(void *, s32);

extern "C" void func_001819F8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s4;
    s32 *p_s3;
    s32 v_s1;
    s32 newVal;
    s32 oldVal;
    p_s4 = buf1;
    func_001803E8(p_s4);
    p_s3 = buf3;
    v_s1 = *p_s4;
    func_001DF250(p_s3, arg3);
    func_0029EA18(buf0, func_00183D70(v_s1, *p_s3));
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(buf0, 0x2);
    func_001DF1F8(p_s3, 0x2);
    func_00180390(p_s4, 0x2);
}
