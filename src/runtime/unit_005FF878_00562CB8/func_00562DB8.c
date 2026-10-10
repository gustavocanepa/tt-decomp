#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562DB8_arg0 {
    char pad0[0x1188];
    s32 unk1188;
};

s32 func_00562DB8(struct func_00562DB8_arg0 *arg0) {
    return arg0->unk1188;
}
