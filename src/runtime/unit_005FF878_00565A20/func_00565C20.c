#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C20_arg0 {
    char pad0[0x5A];
    u8 unk5A;
};

u8 func_00565C20(struct func_00565C20_arg0 *arg0) {
    return arg0->unk5A;
}
