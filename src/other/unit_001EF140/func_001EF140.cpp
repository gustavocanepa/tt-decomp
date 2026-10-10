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

extern "C" void * func_001F0580(void *);
extern "C" void func_001EEF48(void *, void *);
extern "C" void func_001F02A8(void *, s32);
extern "C" void * func_00216658(void *);
extern "C" void func_00216380(void *, s32);

extern "C" void * func_001EF140(s32 *arg0, void *arg1) {
    s32 buf0[4];
    if (arg1 == 0) {
        func_001F0580(buf0);
        *(s32 *)((char *)buf0[0] + 0x10) = 0;
        func_001EEF48(arg0, buf0);
        func_001F02A8(buf0, 0x2);
    } else {
        func_00216658(buf0);
        *(s32 *)((char *)buf0[0] + 0x10) = (s32)arg1;
        func_001EEF48(arg0, buf0);
        func_00216380(buf0, 0x2);
    }
    return arg0;
}
