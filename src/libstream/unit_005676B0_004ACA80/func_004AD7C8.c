#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6998(s32, s32, s32, s32);  /* extern */

extern char D_004ACE48[];
struct func_004AD7C8_arg0 {
    char pad0[0x48];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
};

s32 func_004AD7C8(struct func_004AD7C8_arg0 *arg0) {
    if (arg0->unk48 != 0) {
        arg0->unk48 = 0;
        func_004F6998(arg0->unk4C, arg0->unk50, 8, (s32)D_004ACE48);
    }
}
