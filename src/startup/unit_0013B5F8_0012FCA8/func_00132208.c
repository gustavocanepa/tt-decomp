#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00132208_arg0 {
    char pad0[0x18C];
    s32 unk18C;
};

f32 func_00132208(struct func_00132208_arg0 *arg0) {
    return (f32) arg0->unk18C / 0x1.9000000000000p+6f;
}
