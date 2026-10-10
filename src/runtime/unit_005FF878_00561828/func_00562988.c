#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562988_arg0 {
    char pad0[0x1114];
    s32 unk1114;
};

void func_00562988(struct func_00562988_arg0 *arg0, s32 arg1) {
    arg0->unk1114 = arg1;
}
