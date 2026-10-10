#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562880_arg0 {
    char pad0[0x10D4];
    s32 unk10D4;
};

s32 func_00562880(struct func_00562880_arg0 *arg0) {
    return arg0->unk10D4;
}
