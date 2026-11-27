#include "types.h"

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

struct func_004BD120_v_s4 {
    char pad0[0x40];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s8 unk4C;
};

extern "C" void func_004BD120(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    char *v_s4;
    v_s4 = (char *)&D_00776BC0;
    func_004F4348(*(s32 *)(char *)v_s4);
    ((struct func_004BD120_v_s4 *)v_s4)->unk40 = (s32)arg0;
    ((struct func_004BD120_v_s4 *)v_s4)->unk44 = (s32)arg1;
    ((struct func_004BD120_v_s4 *)v_s4)->unk48 = arg2;
    ((struct func_004BD120_v_s4 *)v_s4)->unk4C = (s8)0;
    if (arg3 != 0) {
        func_004F7B74((char *)v_s4 + 0x4c, arg3);
    }
    func_004F45D8(v_s4, 0x1, 0, 0, 0);
}
