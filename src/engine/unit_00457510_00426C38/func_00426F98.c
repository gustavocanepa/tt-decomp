#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426F98_arg0 {
    char pad0[0x438];
    s32 unk438;
};

s32 func_00426F98(struct func_00426F98_arg0 *arg0) {
    return arg0->unk438;
}
