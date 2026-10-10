#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540B08_arg0 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

f32 func_00540B08(struct func_00540B08_arg0 *arg0) {
    return arg0->unk8 + arg0->unkC + arg0->unk10;
}
