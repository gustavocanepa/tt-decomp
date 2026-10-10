#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562188_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

u32 func_00562188(struct func_00562188_arg0 *arg0) {
    return (u32) ~arg0->unk8210 >> 0x1F;
}
