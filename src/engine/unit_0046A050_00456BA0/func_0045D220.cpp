#include "types.h"

extern char D_005DA268[];

struct Buf {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0C[0x14];
    void *unk20;
};

extern "C" void func_0045D2B0(struct Buf *b);

extern "C" void func_0045D220(struct Buf *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk20 = D_005DA268;
    arg0->unk8 = 0;
    return func_0045D2B0(arg0);
}
