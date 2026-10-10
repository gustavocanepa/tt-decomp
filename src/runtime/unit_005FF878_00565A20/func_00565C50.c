#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C50_arg0 {
    char pad0[0x5C];
    u8 unk5C;
};

u8 func_00565C50(struct func_00565C50_arg0 *arg0) {
    return arg0->unk5C;
}
