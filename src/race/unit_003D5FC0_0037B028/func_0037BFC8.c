#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
void *func_00339C70(s32);                           /* extern */

void *func_0037BFC8(void *arg0) {
    s32 *temp_v0;
    void *temp_v0_2;

    temp_v0 = func_00339C70(M2C_FIELD(arg0, s32 *, 0x138) + 0x10);
    temp_v0_2 = M2C_FIELD(temp_v0, void **, 0x64);
    ({ VEntry *e1_ = (VEntry *)((char *)temp_v0_2 + 0xE8); ((void (*)(void *, s32))e1_->fn)((char *)temp_v0 + e1_->delta, M2C_FIELD(arg0, s32 *, 0x138) + 0x148); });
    return temp_v0;
}
