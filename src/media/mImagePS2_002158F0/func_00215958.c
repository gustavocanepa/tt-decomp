#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00215958_arg0 {
    char pad0[0x1C];
    f32 unk1C;
};

f32 func_00215958(struct func_00215958_arg0 *arg0) {
    return arg0->unk1C;
}
