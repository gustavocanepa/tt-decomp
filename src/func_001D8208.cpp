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

extern "C" void func_001D7C18(void *);
extern "C" void func_001DA0E8(void *, s32, s32, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_001D7BC0(void *, s32);

extern "C" void func_001D8208(s32 *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s3;
    s32 newVal;
    s32 oldVal;
    p_s3 = buf1;
    func_001D7C18(p_s3);
    func_001DA0E8(buf0, *p_s3, arg2, arg3);
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
    func_001D7BC0(buf0, 0x2);
    func_001D7BC0(p_s3, 0x2);
}
