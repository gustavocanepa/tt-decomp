#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_001FFD78_arg0 {
    char pad0[0x114];
    u32 unk114;
};

f32 func_001FFD78(struct func_001FFD78_arg0 *arg0) {
    return (f32)arg0->unk114 / 60.0f;
}
