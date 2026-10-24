#include "types.h"

extern "C" s32 func_003C5AE8(char *arg0) {
    s32 i;
    s32 n = 0;

    for (i = 0; i < 8; i++) {
        if (*(s32 *)(arg0 + 0x110 + i * 4) != 0) {
            n++;
        }
    }
    return n;
}
