#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C40_arg0 {
    char pad0[0x56];
    u8 unk56;
};

u8 func_00565C40(struct func_00565C40_arg0 *arg0) {
    return arg0->unk56;
}
