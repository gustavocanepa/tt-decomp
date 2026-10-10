#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046F0F8(s32);                     /* extern */

struct func_001C8B78_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_001C8B78(struct func_001C8B78_arg0 *arg0) {
    if (arg0->unk4 == 2) {
        func_0046F0F8(7);
    }
}
