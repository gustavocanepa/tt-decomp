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

extern "C" s32 HValue__isValid(void *);
extern "C" s32 func_002BB3A8(void *);
extern "C" void func_002A7A30(void *);
extern "C" void func_002ADB50(void *, void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_002AD780(void *, s32);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A4988(void *, s32, void *);
extern "C" void func_002BC0E0(void *, s32);

extern "C" void mStaticDefine__execute(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    char *v_s1;
    char *v_s3;
    s32 v_s4;
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    v_s1 = (char *)arg0 + 0xc;
    v_s3 = (char *)arg0 + 0x8;
    if (HValue__isValid(v_s1) == 0) {
        v_s4 = func_002BB3A8(arg1);
        p_s2 = buf2;
        func_002A7A30(p_s2);
        func_002ADB50(buf0, v_s3, p_s2);
        if ((char *)v_s1 != (char *)buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *(s32 *)(char *)v_s1;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *(s32 *)(char *)v_s1 = newVal;
        }
        func_002AD780(buf0, 0x2);
        func_002A75A8(p_s2, 0x2);
        func_002A4988(buf0, v_s4, v_s1);
        func_002BC0E0(buf0, 0x2);
    }
}
