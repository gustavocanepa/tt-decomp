#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560618_arg0 {
    char pad0[0x900];
    s32 unk900;
};

void func_00560618(struct func_00560618_arg0 *arg0, s32 arg1) {
    arg0->unk900 = arg1;
}
