/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA440(s32);                         /* extern */
s32 func_00503ED0();                            /* extern */

void func_00503F90(s32 arg0) {
    func_00503ED0();
    func_004FA440(arg0);
}
