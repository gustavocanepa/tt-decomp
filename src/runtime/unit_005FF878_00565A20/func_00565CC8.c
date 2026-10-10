#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565CC8_arg0 {
    char pad0[0x6B];
    u8 unk6B;
};

u8 func_00565CC8(struct func_00565CC8_arg0 *arg0) {
    return arg0->unk6B;
}
