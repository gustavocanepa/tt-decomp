#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00467370(s32, s32);                /* extern */

struct func_00418F10_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

s32 func_00418F10(struct func_00418F10_arg0 *arg0) {
    s32 temp_v0;

    if (arg0 != NULL) {
        temp_v0 = arg0->unk1C;
        if (temp_v0 != 0) {
            func_00467370(temp_v0, -1);
        }
    }
}
