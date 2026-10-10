#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A58_arg0 {
    char pad0[0x1178];
    s32 unk1178;
};

s32 func_00559A58(struct func_00559A58_arg0 *arg0) {
    return arg0->unk1178;
}
