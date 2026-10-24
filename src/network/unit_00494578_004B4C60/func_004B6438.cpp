#include "types.h"

struct Obj {
    char pad[0x40];
    s32 unk40;
    char pad2[0xC0 - 0x44];
    s32 unkC0;
};

extern "C" void func_004F4348(s32 arg0);
extern struct Obj D_00774100;

extern "C" s32 func_004B6438(void) {
    func_004F4348(D_00774100.unk40);
    return D_00774100.unkC0 == 0;
}
