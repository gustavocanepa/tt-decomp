#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551540_arg0 {
    char pad0[0xE3F0];
    s32 unkE3F0;
};

s32 func_00551540(struct func_00551540_arg0 *arg0) {
    return arg0->unkE3F0;
}
