#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035D618_arg0 {
    char pad0[0xEC];
    s32 unkEC;
};

void func_0035D618(struct func_0035D618_arg0 *arg0, s32 arg1) {
    arg0->unkEC = arg1;
}
