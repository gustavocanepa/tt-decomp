#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005A2CA8[];
struct func_004E57B0_arg0 {
    s32 unk0;
    char pad4[0x30];
    void *unk34;
};

void func_004E57B0(struct func_004E57B0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    if (!(temp_v0 & 0x80)) {
        arg0->unk0 = (s32) (temp_v0 | 0x80);
        arg0->unk34 = (void *) *(void **)(s32)D_005A2CA8;
        *(void **)(s32)D_005A2CA8 = arg0;
    }
}
