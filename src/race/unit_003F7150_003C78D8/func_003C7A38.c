#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003C7A00();                            /* extern */
s32 func_003C7A80(s32);                         /* extern */

s32 func_003C7A38(s32 *arg0, s32 arg1) {
    func_003C7A00();
    *arg0 = arg1;
    if (arg1 != 0) {
        func_003C7A80(arg1);
    }
}
