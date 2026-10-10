#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417E68_arg0 {
    char pad0[0x1F0];
    f32 unk1F0;
};

f32 func_00417E68(struct func_00417E68_arg0 *arg0) {
    return arg0->unk1F0;
}
