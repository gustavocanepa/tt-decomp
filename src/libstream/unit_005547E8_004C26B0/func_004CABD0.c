#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C9F20();                            /* extern */

extern char D_005DB380[];
struct func_004CABD0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_004CABD0(struct func_004CABD0_arg0 *arg0) {
    func_004C9F20();
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_005DB380;
}
