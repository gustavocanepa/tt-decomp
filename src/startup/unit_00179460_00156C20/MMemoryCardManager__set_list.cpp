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

extern "C" void func_00156538(void *);
extern "C" void func_00159750(void *, void *);
extern "C" void func_001596F8(void *, s32);
extern "C" void func_00198D50(s32);
extern "C" void func_001564E0(void *, s32);

struct MMemoryCardManager__set_list_v_s1 {
    char pad0[0x678];
    s32 unk678;
};

extern "C" void MMemoryCardManager__set_list(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 v_s1;
    if (arg2 > 0) {
        func_00156538(buf0);
        p_s0 = buf1;
        v_s1 = *(s32 *)((char *)buf0[0] + 0x20);
        func_00159750(p_s0, arg3);
        ((struct MMemoryCardManager__set_list_v_s1 *)v_s1)->unk678 = *(s32 *)((char *)(*p_s0) + 0x10);
        func_001596F8(p_s0, 0x2);
        func_00198D50(*(s32 *)((char *)buf0[0] + 0x20));
        func_001564E0(buf0, 0x2);
    }
}
