#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00535818(void *);                          /* extern */
s32 func_00544038(void *, s32);                 /* extern */

struct func_003966E8_arg0 {
    char pad0[0x96EC];
    s32 unk96EC;
};

s32 Pitmen__getCameraRandom(struct func_003966E8_arg0 *arg0) {
    s8 sp[0x10];
    s32 temp_s0;

    temp_s0 = arg0->unk96EC;
    func_00544038(sp, temp_s0);
    arg0->unk96EC = func_00535818(sp);
    return temp_s0;
}
