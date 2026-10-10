#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560268_arg0 {
    char pad0[0x1C4];
    s32 unk1C4;
};

s32 func_00560268(struct func_00560268_arg0 *arg0) {
    return arg0->unk1C4;
}
