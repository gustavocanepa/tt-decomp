#include "types.h"

extern "C" s32 func_003F7658(void *arg0) {
    char *self = (char *)arg0;
    s32 n = *(s32 *)(self + 0xC6C);
    if (n < 0) {
        return 0;
    }
    *(s32 *)(self + 0xB28) = n;
    __builtin_memcpy(self + 0xB2C, self + 0xC70, 0x100);
    return 1;
}
