#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00557088_arg0 {
    char pad0[0x28];
    f32 unk28;
};

f32 func_00557088(struct func_00557088_arg0 *arg0) {
    return arg0->unk28;
}
