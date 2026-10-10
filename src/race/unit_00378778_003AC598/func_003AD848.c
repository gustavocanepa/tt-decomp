#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041E670();                             /* extern */

s32 func_003AD848(s32 arg0) {
    if ((arg0 != 0) && ((func_0041E670() == 0x46) || (func_0041E670(arg0) == 0x47))) {
        return 1;
    }
    return 0;
}
