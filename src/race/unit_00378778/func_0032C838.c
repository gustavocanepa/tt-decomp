#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0032C838_arg0 {
    char pad0[0x180];
    s32 unk180;
};

void func_0032C838(struct func_0032C838_arg0 *arg0, s32 arg1) {
    arg0->unk180 = arg1;
}
