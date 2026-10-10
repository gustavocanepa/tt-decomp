#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00410840_arg0 {
    char pad0[0x10];
    u8 unk10;
};

u8 func_00410840(struct func_00410840_arg0 *arg0) {
    return arg0->unk10;
}
