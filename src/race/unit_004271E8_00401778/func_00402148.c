#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00402148_temp_a0 {
    char pad0[0x4];
    s32 unk4;
};

void *func_00402148(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = arg0 + 0x233FC;
    if (arg1 < ((struct func_00402148_temp_a0 *)temp_a0)->unk4) {
        return temp_a0 + (arg1 * 0x54) + 0xC;
    }
    return NULL;
}
