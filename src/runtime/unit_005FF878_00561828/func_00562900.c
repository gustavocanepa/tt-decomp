#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562900_arg0 {
    char pad0[0x10F4];
    s32 unk10F4;
};

s32 func_00562900(struct func_00562900_arg0 *arg0) {
    return arg0->unk10F4;
}
