#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00462838(void *);                      /* extern */
s32 func_00462CA0();                            /* extern */

struct func_004631A8_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x97C];
    s32 unk988;
};

s32 func_004631A8(struct func_004631A8_arg0 *arg0) {
    s32 temp_s0;

    func_00462CA0();
    temp_s0 = ((((arg0->unk8 * 2) + arg0->unk988) * 4) + 0x1F) & ~0xF;
    func_00462838(arg0);
    return temp_s0;
}
