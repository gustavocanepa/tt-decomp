#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RefCounter__structor_0();                            /* extern */

extern char D_005DAF10[];
struct func_004B3248_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

void func_004B3248(struct func_004B3248_arg0 *arg0, s32 arg1, s32 arg2) {
    RefCounter__structor_0();
    arg0->unk20 = arg1;
    arg0->unk24 = arg2;
    arg0->unk1C = (s32)D_005DAF10;
    arg0->unk28 = 0;
}
