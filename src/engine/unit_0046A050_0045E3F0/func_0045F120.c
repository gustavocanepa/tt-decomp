#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0045F0A8(void *, f32);                 /* extern */
f32 func_0045F280();                                /* extern */

struct func_0045F120_arg0 {
    char pad0[0x2C];
    s32 unk2C;
    char pad30[0x18];
    s32 unk48;
    char pad4C[0x34];
    s32 unk80;
    char pad84[0x10];
    s32 unk94;
};

void func_0045F120(struct func_0045F120_arg0 *arg0) {
    if ((arg0->unk2C != 0) && (arg0->unk80 != 0)) {
        arg0->unk48 = 0;
        func_0045F0A8(arg0, func_0045F280());
        arg0->unk94 = 0;
    }
}
