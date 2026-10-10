#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417EA8_arg0 {
    char pad0[0x200];
    f32 unk200;
};

f32 func_00417EA8(struct func_00417EA8_arg0 *arg0) {
    return arg0->unk200;
}
