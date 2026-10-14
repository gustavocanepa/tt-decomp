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

extern "C" void func_001CE820(void *);
extern "C" void func_001C1380(void *, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_001C13B0(void *, s32);
extern "C" void func_001D9D90(void *, s32);

extern "C" void func_001266D0(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    p_s1 = (s32 *)((char *)arg0 + 0xe4);
    func_001CE820((char *)arg0 + 0xb4);
    buf1[0] = 0;
    func_001C1380(buf0, buf1);
    if ((char *)p_s1 != (char *)buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *p_s1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *p_s1 = newVal;
    }
    func_001C13B0(buf0, 0x2);
    func_001D9D90(arg0, 0);
}
