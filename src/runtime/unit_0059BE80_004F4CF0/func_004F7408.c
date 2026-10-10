#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F5140();                                /* extern */

struct func_004F7408_arg0 {
    char pad0[0xC];
    u16 unkC;
};

s32 func_004F7408(struct func_004F7408_arg0 *arg0) {
    if ((arg0->unkC & 9) == 9) {
        return func_004F5140();
    }
    return 0;
}
