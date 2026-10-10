#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_001FC448();                                /* extern */
s32 func_0021A2A0(s32);                         /* extern */

s32 func_0021A7F0(s32 arg0) {
    if (func_001FC448() == 0) {
        func_0021A2A0(arg0);
        return 1;
    }
    return 0;
}
