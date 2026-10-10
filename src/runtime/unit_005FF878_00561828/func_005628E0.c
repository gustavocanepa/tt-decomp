#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005628E0_arg0 {
    char pad0[0x10EC];
    s32 unk10EC;
};

s32 func_005628E0(struct func_005628E0_arg0 *arg0) {
    return arg0->unk10EC;
}
