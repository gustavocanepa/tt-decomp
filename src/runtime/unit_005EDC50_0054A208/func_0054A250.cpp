#include "types.h"

struct Sub {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_0054A250(char *arg0) {
    Sub *p = (Sub *)(arg0 + 0x2C);
    return (s32)(p->unk8 - p->unk4) >> 2;
}
