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

extern char D_00776BC0[];
extern "C" void func_004F4348(s32);
extern "C" void func_004F7B74(void *, void *);
extern "C" void func_004F45D8(void *, s32, s32, s32, s32);

extern "C" void func_004BD120(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    char *v_s4;
    v_s4 = (char *)&D_00776BC0;
    func_004F4348(*(s32 *)(char *)v_s4);
    *(s32 *)((char *)v_s4 + 0x40) = (s32)arg0;
    *(s32 *)((char *)v_s4 + 0x44) = (s32)arg1;
    *(s32 *)((char *)v_s4 + 0x48) = arg2;
    *(s8 *)((char *)v_s4 + 0x4c) = (s8)0;
    if (arg3 != 0) {
        func_004F7B74((char *)v_s4 + 0x4c, arg3);
    }
    func_004F45D8(v_s4, 0x1, 0, 0, 0);
}
