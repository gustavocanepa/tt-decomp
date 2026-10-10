#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562E08_arg0 {
    char pad0[0x1234];
    s32 unk1234;
};

s32 func_00562E08(struct func_00562E08_arg0 *arg0) {
    return arg0->unk1234;
}
