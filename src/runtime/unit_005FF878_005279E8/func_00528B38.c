#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00528B38_arg0 {
    char pad0[0x10];
    f32 unk10;
};

f32 func_00528B38(struct func_00528B38_arg0 *arg0) {
    return arg0->unk10;
}
