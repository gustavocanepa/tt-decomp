#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00310520(void *);
struct func_00310610_arg0 {
    char pad0[0x7E8];
    f32 unk7E8;
};

s32 func_00310610(struct func_00310610_arg0 *arg0) {
    if (func_00310520(arg0) == 0) return 0;
    return arg0->unk7E8 * 8.0f + 0.5f;
}
