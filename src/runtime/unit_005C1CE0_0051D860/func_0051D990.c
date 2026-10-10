#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051D990_arg0 {
    char pad0[0x1F6C];
    s32 unk1F6C;
};

void func_0051D990(struct func_0051D990_arg0 *arg0, s32 arg1) {
    arg0->unk1F6C = arg1;
}
