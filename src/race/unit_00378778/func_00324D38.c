#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00324D38_arg0 {
    char pad0[0x29C];
    f32 unk29C;
};

f32 func_00324D38(struct func_00324D38_arg0 *arg0) {
    return arg0->unk29C;
}
