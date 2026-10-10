#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003F1F50_arg0 {
    char pad0[0x28];
    s32 unk28;
};

s32 func_003F1F50(struct func_003F1F50_arg0 *arg0) {
    return arg0->unk28;
}
