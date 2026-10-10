#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565EA8_arg0 {
    char pad0[0x93];
    u8 unk93;
};

s32 func_00565EA8(struct func_00565EA8_arg0 *arg0) {
    return arg0->unk93 * 0xA;
}
