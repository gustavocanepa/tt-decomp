#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002CED90_arg0 {
    char pad0[0xD06C];
    s32 unkD06C;
};

s32 func_002CED90(struct func_002CED90_arg0 *arg0) {
    return arg0->unkD06C;
}
