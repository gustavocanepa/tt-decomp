#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562828_arg0 {
    char pad0[0x10BC];
    s32 unk10BC;
};

void func_00562828(struct func_00562828_arg0 *arg0, s32 arg1) {
    arg0->unk10BC = arg1;
}
