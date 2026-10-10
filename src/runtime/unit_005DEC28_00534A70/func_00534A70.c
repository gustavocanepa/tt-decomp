#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00534A70_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_00534A70(struct func_00534A70_arg0 *arg0) {
    return arg0->unk10 - 1;
}
