#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F1118();                            /* extern */
s32 func_002F8110(void *);                      /* extern */

struct DynamicsConductorSinglePlayer__virtual_26_arg0 {
    char pad0[0x20A2B];
    s8 unk20A2B;
    char pad20A2C[0x2F20];
    s16 unk2394C;
    u8 unk2394E;
    u8 unk2394F;
};

void DynamicsConductorSinglePlayer__virtual_26(struct DynamicsConductorSinglePlayer__virtual_26_arg0 *arg0) {
    func_002F1118();
    if ((arg0->unk2394E != 0) && (arg0->unk2394C < 0) && (arg0->unk2394F != 0)) {
        arg0->unk20A2B = 1;
    }
    func_002F8110(arg0);
}
