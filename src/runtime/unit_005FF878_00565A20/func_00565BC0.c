#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565BC0_arg0 {
    char pad0[0x42];
    u8 unk42;
};

u8 func_00565BC0(struct func_00565BC0_arg0 *arg0) {
    return arg0->unk42;
}
