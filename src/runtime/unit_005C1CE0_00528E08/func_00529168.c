#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00529168_arg0 {
    char pad0[0x180];
    s32 unk180;
};

s32 func_00529168(struct func_00529168_arg0 *arg0) {
    return arg0->unk180;
}
