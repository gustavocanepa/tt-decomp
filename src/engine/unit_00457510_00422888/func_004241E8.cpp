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

extern "C" void func_00423C60(void *, s32);

struct func_004241E8_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};
struct func_004241E8_arg1 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" void func_004241E8(s32 *arg0, void *arg1) {
    s32 v_s0;
    if (((struct func_004241E8_arg0 *)arg0)->unk4 >= 0) {
        v_s0 = ((struct func_004241E8_arg1 *)arg1)->unk8;
        v_s0 = (v_s0 - *(s32 *)(char *)arg1);
        ((struct func_004241E8_arg0 *)arg0)->unk8 = (v_s0 - ((struct func_004241E8_arg0 *)arg0)->unk4);
        ((struct func_004241E8_arg1 *)arg1)->unk8 = (*(s32 *)(char *)arg1 + ((struct func_004241E8_arg0 *)arg0)->unk4);
        func_00423C60(arg1, *(s32 *)(char *)arg0);
        func_00423C60(arg1, ((struct func_004241E8_arg0 *)arg0)->unk8);
        ((struct func_004241E8_arg1 *)arg1)->unk8 = (*(s32 *)(char *)arg1 + v_s0);
    }
}
