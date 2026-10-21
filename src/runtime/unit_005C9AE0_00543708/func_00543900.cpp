#include "types.h"

struct S005DAA98 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x100];
    void *unk10C;
};

extern "C" char D_005BE110[];

extern "C" void func_00543900(struct S005DAA98 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk10C = D_005BE110;
    arg0->unk8 = 0;
}
