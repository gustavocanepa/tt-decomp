#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560258_arg0 {
    char pad0[0x1CC];
    s32 unk1CC;
};

s32 func_00560258(struct func_00560258_arg0 *arg0) {
    return arg0->unk1CC;
}
