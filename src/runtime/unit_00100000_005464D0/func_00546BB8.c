#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546BB8_arg0 {
    char pad0[0x110];
    s32 unk110;
};

s32 func_00546BB8(struct func_00546BB8_arg0 *arg0) {
    return arg0->unk110;
}
