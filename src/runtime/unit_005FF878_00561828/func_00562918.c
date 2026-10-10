#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562918_arg0 {
    char pad0[0x10F8];
    s32 unk10F8;
};

void func_00562918(struct func_00562918_arg0 *arg0, s32 arg1) {
    arg0->unk10F8 = arg1;
}
