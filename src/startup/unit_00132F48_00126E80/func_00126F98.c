#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00126F98_arg0 {
    char pad0[0x304];
    s32 unk304;
};

s32 func_00126F98(struct func_00126F98_arg0 *arg0) {
    return *(s32 *)(0x579908 + (arg0->unk304 * 4));
}
