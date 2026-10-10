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

extern "C" void func_0014D580(void *);
extern "C" void func_0014D528(void *, s32);
extern "C" void func_00132898(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00128418(void *, s32);

extern "C" void func_0014E000(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    func_0014D580(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
    func_0014D528(buf0, 0x2);
    func_00132898(buf0, v_s0 + 0x7d08);
    *(s32 *)((char *)buf0[0] + 0x188) = *(s32 *)((char *)((0x10000 + v_s0)) - 0x7DF0);
    if ((char *)arg0 != (char *)buf0) {
        v_s0 = buf0[0];
        if (v_s0 != 0) {
            func_002C0FE8(v_s0);
        }
        if (*(s32 *)(char *)arg0 != 0) {
            func_002C1050(*(s32 *)(char *)arg0);
        }
        *(s32 *)(char *)arg0 = v_s0;
    }
    func_00128418(buf0, 0x2);
}
