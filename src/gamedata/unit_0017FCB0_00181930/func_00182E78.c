#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00182E78_arg0 {
    char pad0[0xD0];
    s32 unkD0;
    s32 unkD4;
};

void func_00182E78(struct func_00182E78_arg0 *arg0, s32 arg1) {
    arg0->unkD4 = (s32) (arg1 != 0);
    arg0->unkD0 = 1;
}
