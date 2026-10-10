#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F44B8();                            /* extern */

extern char D_005DB1C8[];
struct func_004C1F28_arg0 {
    char pad0[0x38];
    s32 unk38;
};

void func_004C1F28(struct func_004C1F28_arg0 *arg0) {
    func_004F44B8();
    arg0->unk38 = (s32)D_005DB1C8;
}
