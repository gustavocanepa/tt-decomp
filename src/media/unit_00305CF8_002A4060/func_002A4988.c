#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A4518(s32, s32, s32 *);             /* extern */
s32 func_002BC0C8(s32, s32 *);                  /* extern */
s32 func_002BC248(s32);                             /* extern */

s32 func_002A4988(s32 arg0, s32 arg1, s32 *arg2) {
    func_002A4518(arg1, func_002BC248(*arg2), arg2);
    func_002BC0C8(arg0, arg2);
    return arg0;
}
