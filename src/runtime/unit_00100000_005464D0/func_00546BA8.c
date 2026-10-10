#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546BA8_arg0 {
    char pad0[0x10C];
    s32 unk10C;
};

s32 func_00546BA8(struct func_00546BA8_arg0 *arg0) {
    return arg0->unk10C;
}
