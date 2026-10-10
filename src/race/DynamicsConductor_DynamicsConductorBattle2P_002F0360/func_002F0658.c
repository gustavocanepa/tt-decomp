#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0034B1A8(s32);                         /* extern */

struct func_002F0658_arg0 {
    char pad0[0x20A20];
    s32 unk20A20;
};

void func_002F0658(struct func_002F0658_arg0 *arg0) {
    func_0034B1A8(arg0->unk20A20);
}
