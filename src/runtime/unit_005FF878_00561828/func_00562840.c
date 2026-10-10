#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562840_arg0 {
    char pad0[0x10C4];
    s32 unk10C4;
};

s32 func_00562840(struct func_00562840_arg0 *arg0) {
    return arg0->unk10C4;
}
