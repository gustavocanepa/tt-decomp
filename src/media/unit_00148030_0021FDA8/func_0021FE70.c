#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0021FE70_arg0 {
    char pad0[0x60];
    f32 unk60;
};

f32 func_0021FE70(struct func_0021FE70_arg0 *arg0) {
    return 0x1.6800000000000p+8f / (arg0->unk60 * 0x1.e000000000000p+5f);
}
