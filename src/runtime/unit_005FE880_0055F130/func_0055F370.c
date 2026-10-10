#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D6FF0[];
struct func_0055F370_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_0055F370(struct func_0055F370_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk8 = arg2;
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)D_005D6FF0;
}
