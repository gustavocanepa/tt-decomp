#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A4348(s32, s32);                    /* extern */
s32 func_0054BCB0(void *);                      /* extern */

struct func_002A44C8_temp_v1 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_002A44C8(s32 arg0, s32 arg1) {
    struct func_002A44C8_temp_v1 *temp_v1;

    temp_v1 = arg0 + 0x18;
    if (temp_v1->unk8 != 0) {
        func_0054BCB0(temp_v1);
        func_002A4348(arg0, arg1);
    }
}
