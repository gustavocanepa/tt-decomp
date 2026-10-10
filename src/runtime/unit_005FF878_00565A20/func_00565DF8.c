#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565DF8_arg0 {
    char pad0[0x98];
    u8 unk98;
};

s32 func_00565DF8(struct func_00565DF8_arg0 *arg0) {
    return arg0->unk98 * 0xA;
}
