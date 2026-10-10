#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562698_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void func_00562698(struct func_00562698_arg0 *arg0, s32 arg1) {
    arg0->unk80 = arg1;
}
