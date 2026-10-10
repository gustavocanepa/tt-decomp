#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004021A8_temp_a0 {
    char pad0[0x4];
    s32 unk4;
};

void *func_004021A8(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = arg0 + 0x23F80;
    if (arg1 < ((struct func_004021A8_temp_a0 *)temp_a0)->unk4) {
        return temp_a0 + (arg1 * 0x34) + 0xC;
    }
    return NULL;
}
