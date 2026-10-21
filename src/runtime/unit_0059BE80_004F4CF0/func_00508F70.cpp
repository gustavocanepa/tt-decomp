#include "types.h"

extern "C" s32 func_00508F70(const u8 *a, const u8 *b, s32 n) {
    while (n != 0) {
        s32 x = *a++;
        s32 y = *b++;
        if (x != y) return x - y;
        n--;
    }
    return 0;
}
