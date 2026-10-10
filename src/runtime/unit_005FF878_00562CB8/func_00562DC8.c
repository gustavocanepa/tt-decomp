#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562DC8_arg0 {
    char pad0[0x1180];
    s32 unk1180;
};

s32 func_00562DC8(struct func_00562DC8_arg0 *arg0) {
    return arg0->unk1180;
}
