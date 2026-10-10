#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A08_arg0 {
    char pad0[0x1174];
    s8 unk1174;
};

s32 func_00559A08(struct func_00559A08_arg0 *arg0) {
    return arg0->unk1174 != 0;
}
