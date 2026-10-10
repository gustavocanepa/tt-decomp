#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00476E90_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
};

s32 func_00476E90(struct func_00476E90_arg0 *arg0) {
    return arg0->unkC + arg0->unk10;
}
