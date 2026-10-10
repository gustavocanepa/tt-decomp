#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00563340_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

void func_00563340(struct func_00563340_arg0 *arg0, s32 arg1) {
    arg0->unkAC = arg1;
}
