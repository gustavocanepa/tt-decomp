#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 GT4_Motion__PlayList__find_segment_const_2();                                /* extern */

struct func_003F1A20_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 GT4_Motion__PlayList__getElement(struct func_003F1A20_arg0 *arg0) {
    return arg0->unk4 + (GT4_Motion__PlayList__find_segment_const_2() << 5);
}
