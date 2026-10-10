#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001A6EB8(s32);                         /* extern */

struct func_00182C38_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

void func_00182C38(struct func_00182C38_arg0 *arg0) {
    func_001A6EB8(arg0->unkB4);
}
