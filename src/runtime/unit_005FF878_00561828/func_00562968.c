#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562968_arg0 {
    char pad0[0x110C];
    s32 unk110C;
};

void func_00562968(struct func_00562968_arg0 *arg0, s32 arg1) {
    arg0->unk110C = arg1;
}
