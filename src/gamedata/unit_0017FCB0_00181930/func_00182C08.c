#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001A6E20(s32);                             /* extern */

struct func_00182C08_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

s32 func_00182C08(struct func_00182C08_arg0 *arg0) {
    return func_001A6E20(arg0->unkB4) != 0;
}
