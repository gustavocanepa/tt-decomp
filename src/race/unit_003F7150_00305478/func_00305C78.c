#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00305C78_arg0 {
    char pad0[0x738];
    s32 unk738;
};

s32 func_00305C78(struct func_00305C78_arg0 *arg0) {
    return arg0->unk738;
}
