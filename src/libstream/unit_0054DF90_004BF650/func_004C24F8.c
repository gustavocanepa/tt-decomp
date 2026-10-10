#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C24B0();                                /* extern */

struct func_004C24F8_arg0 {
    char pad0[0x40];
    s32 unk40;
};

s32 func_004C24F8(struct func_004C24F8_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0_2 = func_004C24B0();
    temp_v0 = arg0->unk40;
    arg0->unk40 = temp_v0_2;
    return temp_v0 != temp_v0_2;
}
