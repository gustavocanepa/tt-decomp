#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C18_arg0 {
    char pad0[0x100];
    f32 unk100;
};

f32 func_00417C18(struct func_00417C18_arg0 *arg0) {
    return arg0->unk100;
}
