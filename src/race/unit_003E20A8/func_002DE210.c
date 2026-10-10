#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002E0040(s32, s32, s32, s32);              /* extern */

struct func_002DE210_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_002DE210(s32 arg0, struct func_002DE210_arg1 *arg1) {
    if (arg1->unkC == 0) {
        arg1->unkC = func_002E0040(arg1->unk4, arg0, arg1->unk0, arg1->unk8);
    }
}
