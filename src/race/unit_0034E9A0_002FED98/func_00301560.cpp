#include "types.h"

extern "C" s32 func_00301560(char *arg0base) {
    u16 *p = (u16 *)(arg0base + 0x5DC);
    u16 flags = *p;

    if ((flags & 0x200) == 0) {
        return 0;
    }
    *p = flags ^ 0x200;
    return 1;
}
