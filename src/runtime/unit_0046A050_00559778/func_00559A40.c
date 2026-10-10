#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A40_arg0 {
    char pad0[0x117E];
    s8 unk117E;
};

s32 func_00559A40(struct func_00559A40_arg0 *arg0) {
    return arg0->unk117E != 0;
}
