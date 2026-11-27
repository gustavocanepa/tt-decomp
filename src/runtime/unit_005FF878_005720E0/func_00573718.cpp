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

extern "C" void func_004F4348(s32);
extern "C" void func_004F43A8(s32, void *);
extern "C" void func_004F45D8(void *, s32, s32, s32, s32);

struct func_00573718_arg0 {
    char pad0[0x40];
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

extern "C" void func_00573718(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    func_004F4348(*(s32 *)(char *)arg0);
    ((struct func_00573718_arg0 *)arg0)->unk40 = (s32)arg1;
    ((struct func_00573718_arg0 *)arg0)->unk44 = arg2;
    ((struct func_00573718_arg0 *)arg0)->unk48 = (s32)arg3;
    func_004F43A8(arg2, arg3);
    func_004F45D8(arg0, 0x3, 0, 0, 0);
}
