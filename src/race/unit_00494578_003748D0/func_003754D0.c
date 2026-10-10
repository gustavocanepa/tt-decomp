#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003CCCB8(s32, s32, s32);               /* extern */
void *func_003CCD90(s32, s32);                  /* extern */

struct func_003754D0_temp_v0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_003754D0(s32 arg0, s32 arg1) {
    s32 temp_s0;
    struct func_003754D0_temp_v0 *temp_v0;

    temp_s0 = arg0 + 0xDF0;
    temp_v0 = func_003CCD90(temp_s0, 8);
    if (temp_v0 != NULL) {
        func_003CCCB8(temp_s0, arg1, temp_v0->unk4);
    }
}
