#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562908_arg0 {
    char pad0[0x10F4];
    s32 unk10F4;
};

void func_00562908(struct func_00562908_arg0 *arg0, s32 arg1) {
    arg0->unk10F4 = arg1;
}
