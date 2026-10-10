#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00324D20_arg0 {
    char pad0[0x260];
    f32 unk260;
};

f32 func_00324D20(struct func_00324D20_arg0 *arg0) {
    return arg0->unk260;
}
