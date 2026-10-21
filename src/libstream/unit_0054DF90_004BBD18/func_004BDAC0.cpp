#include "types.h"

struct func_004CDD80_a0;
extern "C" s32 func_004CDD80(struct func_004CDD80_a0 *a0);

extern "C" s32 D_00598424;

struct func_004BDAC0_a0 {
    char pad[0xC];
    struct func_004CDD80_a0 *child;
};

extern "C" s32 func_004BDAC0(struct func_004BDAC0_a0 *a0) {
    if (D_00598424 == 0) return 0;
    return func_004CDD80(a0->child);
}
