#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C28_arg0 {
    char pad0[0x53];
    u8 unk53;
};

u8 func_00565C28(struct func_00565C28_arg0 *arg0) {
    return arg0->unk53;
}
