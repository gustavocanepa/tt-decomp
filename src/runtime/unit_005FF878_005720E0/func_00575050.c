#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00575050_arg0 {
    char pad0[0x2];
    u16 unk2;
};

s32 func_00575050(struct func_00575050_arg0 *arg0) {
    return arg0->unk2 & 0xF;
}
