#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001FA458_arg0 {
    char pad0[0x140];
    s32 unk140;
};

f32 func_001FA458(struct func_001FA458_arg0 *arg0, f32 fparg0) {
    if (arg0->unk140 != 0) {
        return (0x1.0000000000000p+1f * fparg0) / 0x1.e000000000000p+5f;
    }
    return fparg0 / 0x1.e000000000000p+5f;
}
