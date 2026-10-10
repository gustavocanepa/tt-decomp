#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AB0_arg0 {
    char pad0[0x1144];
    s32 unk1144;
};

s32 func_00562AB0(struct func_00562AB0_arg0 *arg0) {
    return arg0->unk1144;
}
