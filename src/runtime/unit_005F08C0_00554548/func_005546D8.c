#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005546D8_arg0 {
    char pad0[0xE4DC];
    s32 unkE4DC;
};

s32 func_005546D8(struct func_005546D8_arg0 *arg0) {
    return arg0->unkE4DC;
}
