#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562640_arg0 {
    char pad0[0x78];
    s32 unk78;
};

s32 func_00562640(struct func_00562640_arg0 *arg0) {
    return arg0->unk78;
}
