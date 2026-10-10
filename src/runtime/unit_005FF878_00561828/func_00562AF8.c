#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AF8_arg0 {
    char pad0[0x1148];
    s32 unk1148;
};

s32 func_00562AF8(struct func_00562AF8_arg0 *arg0, s32 arg1) {
    return (arg0->unk1148 & arg1) != 0;
}
