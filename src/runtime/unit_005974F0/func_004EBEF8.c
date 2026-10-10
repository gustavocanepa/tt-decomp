#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004E57B0();                            /* extern */

struct func_004EBEF8_arg0 {
    s32 unk0;
    char pad4[0x34];
    s32 unk38;
    char pad3C[0x4];
    s64 unk40;
};

void func_004EBEF8(struct func_004EBEF8_arg0 *arg0) {
    arg0->unk40 = -1;
    arg0->unk0 = (s32) (arg0->unk0 | 0x240C);
    func_004E57B0();
    arg0->unk38 = -1;
}
