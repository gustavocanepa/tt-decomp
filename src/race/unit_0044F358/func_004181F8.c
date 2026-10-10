#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004181F8_arg0 {
    char pad0[0x2C4];
    f32 unk2C4;
};

f32 func_004181F8(struct func_004181F8_arg0 *arg0) {
    return arg0->unk2C4;
}
