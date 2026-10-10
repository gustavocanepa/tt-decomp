#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565CB8_arg0 {
    char pad0[0x6A];
    u8 unk6A;
};

u8 func_00565CB8(struct func_00565CB8_arg0 *arg0) {
    return arg0->unk6A;
}
