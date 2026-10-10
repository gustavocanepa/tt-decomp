#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00529670_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

s32 func_00529670(struct func_00529670_arg0 *arg0) {
    return arg0->unk3C;
}
