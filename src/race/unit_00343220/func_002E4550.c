#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6678(void *, s32, s32);            /* extern */

struct func_002E4550_arg0 {
    char pad0[0x14];
    s8 unk14;
};

void func_002E4550(struct func_002E4550_arg0 *arg0) {
    func_004F6678(arg0, 0, 0x20);
    arg0->unk14 = 1;
}
