#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541808_arg0 {
    char pad0[0x124];
    f32 unk124;
};

f32 func_00541808(struct func_00541808_arg0 *arg0) {
    return arg0->unk124;
}
