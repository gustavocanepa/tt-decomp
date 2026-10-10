/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_004E5828();                            /* extern */

struct func_004E5940_arg0 {
    s32 unk0;
    char pad4[0x20];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

void func_004E5940(struct func_004E5940_arg0 *arg0) {
    if (arg0->unk0 & 0x100) {
        func_004E5828();
    }
    func_004A45D0(arg0->unk24);
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    arg0->unk28 = 0;
}
