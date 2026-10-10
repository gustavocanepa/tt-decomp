#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00576240_arg0 {
    char pad0[0x10];
    s64 unk10;
};

s64 func_00576240(struct func_00576240_arg0 *arg0) {
    return arg0->unk10;
}
