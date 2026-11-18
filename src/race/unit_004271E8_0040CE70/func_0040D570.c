#include "types.h"
s32 func_0040D5A8(char *a, s32 b);
s32 func_0040D570(char *arg0) {
    s32 c = *(s8 *)(arg0 + 0x18);
    if (c == -1) return 0;
    return func_0040D5A8(arg0, c);
}
