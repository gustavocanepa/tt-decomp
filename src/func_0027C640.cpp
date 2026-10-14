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

extern "C" void func_0027BE98(void *, s32);
extern "C" void func_0027BEF0(void *, void *);
extern "C" s32 func_0027E050(s32, s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

extern "C" void func_0027C640(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s3;
    s32 var_s0;
    s32 newVal;
    s32 oldVal;
    func_0027BEF0(buf0, arg1);
    var_s0 = 1;
    if (arg2 > 0) {
        p_s3 = buf1;
        func_0029CF48(p_s3, arg3);
        var_s0 = func_0029E9F0(p_s3[0]);
        func_0029CEF0(p_s3, 0x2);
    } else {
        p_s3 = buf1;
    }
    func_0029EA18(p_s3, func_0027E050(buf0[0], var_s0) != 0);
    if (arg0 != p_s3) {
        newVal = *p_s3;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(p_s3, 0x2);
    func_0027BE98(buf0, 0x2);
}
