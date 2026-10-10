#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536D50_arg0 {
    char pad0[0x11C];
    s32 unk11C;
};

s32 func_00536D50(struct func_00536D50_arg0 *arg0) {
    return arg0->unk11C & 1;
}
