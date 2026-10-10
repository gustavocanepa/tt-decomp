#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418218_arg0 {
    char pad0[0x2CC];
    f32 unk2CC;
};

f32 func_00418218(struct func_00418218_arg0 *arg0) {
    return arg0->unk2CC;
}
