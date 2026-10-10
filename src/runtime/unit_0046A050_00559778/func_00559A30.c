#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A30_arg0 {
    char pad0[0x1176];
    s8 unk1176;
};

s8 func_00559A30(struct func_00559A30_arg0 *arg0) {
    return arg0->unk1176;
}
