#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565D70_arg0 {
    char pad0[0x4A];
    u8 unk4A;
};

u8 func_00565D70(struct func_00565D70_arg0 *arg0) {
    return arg0->unk4A;
}
