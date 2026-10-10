/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u8 func_004DAC28(u8);                               /* extern */

struct func_004DACE0_arg0 {
    char pad0[0x1];
    u8 unk1;
    u8 unk2;
    u8 unk3;
    char pad4[0x1];
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

void func_004DACE0(struct func_004DACE0_arg0 *arg0) {
    arg0->unk7 = func_004DAC28(arg0->unk7);
    arg0->unk6 = func_004DAC28(arg0->unk6);
    arg0->unk5 = func_004DAC28(arg0->unk5);
    arg0->unk3 = func_004DAC28(arg0->unk3);
    arg0->unk2 = func_004DAC28(arg0->unk2);
    arg0->unk1 = func_004DAC28(arg0->unk1);
}
