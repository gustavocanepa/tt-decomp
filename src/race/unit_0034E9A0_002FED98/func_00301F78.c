#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00301F78_arg0 {
    char pad0[0x7E5];
    u8 unk7E5;
};

u32 func_00301F78(struct func_00301F78_arg0 *arg0) {
    return (u8) arg0->unk7E5 >> 4;
}
