#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005CE0C0[];
struct func_003404C0_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_003404C0(struct func_003404C0_arg0 *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)D_005CE0C0;
}
