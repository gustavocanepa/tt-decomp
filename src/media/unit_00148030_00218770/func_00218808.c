#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00218808_arg0 {
    char pad0[0x68];
    f32 unk68;
    f32 unk6C;
    f32 unk70;
};

f32 func_00218808(struct func_00218808_arg0 *arg0) {
    return (arg0->unk6C - arg0->unk70) / arg0->unk68;
}
