#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00402208_arg0 {
    char pad0[0x23F88];
    s32 unk23F88;
};

s32 func_00402208(struct func_00402208_arg0 *arg0) {
    return arg0->unk23F88;
}
