#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540AC8_arg0 {
    char pad0[0xC];
    f32 unkC;
};

f32 func_00540AC8(struct func_00540AC8_arg0 *arg0) {
    return arg0->unkC;
}
