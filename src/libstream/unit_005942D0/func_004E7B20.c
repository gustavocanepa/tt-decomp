#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004E5940();                            /* extern */

struct func_004E7B20_arg0_unk50 {
    char pad0[0x4C];
    s32 (*unk4C)(void *, s32, s32);
};
struct func_004E7B20_arg0 {
    char pad0[0x24];
    s32 unk24;
    char pad28[0x28];
    struct func_004E7B20_arg0_unk50 *unk50;
};

void func_004E7B20(struct func_004E7B20_arg0 *arg0, s32 arg1, s32 arg2) {
    if (arg0->unk24 != 0) {
        func_004E5940();
    }
    arg0->unk50->unk4C(arg0, arg1, arg2);
}
