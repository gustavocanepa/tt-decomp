#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562850_arg0 {
    char pad0[0x10C8];
    s32 unk10C8;
};

s32 func_00562850(struct func_00562850_arg0 *arg0) {
    return arg0->unk10C8;
}
