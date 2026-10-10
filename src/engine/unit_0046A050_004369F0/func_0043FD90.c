#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A260(s32, s32, s32);                   /* extern */

struct func_0043FD90_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

void func_0043FD90(struct func_0043FD90_arg0 *arg0, s32 arg1) {
    if (arg0->unkC == 0) {
        arg0->unkC = func_0043A260(arg1, arg0->unk0, arg0->unk4);
    }
}
