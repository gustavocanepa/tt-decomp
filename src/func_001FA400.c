#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001FA400_arg0 {
    char pad0[0x140];
    s32 unk140;
};

s32 func_001FA400(struct func_001FA400_arg0 *arg0, f32 fparg0) {
    if (arg0->unk140 != 0) {
        return (s32)(fparg0 * 0.5f * 60.0f);
    }
    return (s32)(fparg0 * 60.0f);
}
