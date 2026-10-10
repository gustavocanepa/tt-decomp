#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003F6D60();                                /* extern */

struct func_003FB640_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_003FB640(struct func_003FB640_arg0 *arg0) {
    return (arg0->unk10 & 0xFFFFFF) + func_003F6D60();
}
