#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00529160_arg0 {
    char pad0[0x1E8];
    s32 unk1E8;
};

void func_00529160(struct func_00529160_arg0 *arg0, s32 arg1) {
    arg0->unk1E8 = arg1;
}
