#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003CF128_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_003CF128(void *arg0) {
    ((struct func_003CF128_arg0 *)arg0)->unk8 = (s32) (arg0 + 0x1C);
}
