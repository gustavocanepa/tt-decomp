#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564B70_arg0 {
    char pad0[0x48];
    s64 unk48;
};

s64 func_00564B70(struct func_00564B70_arg0 *arg0) {
    return arg0->unk48;
}
