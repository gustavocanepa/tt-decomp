/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041F810();                                /* extern */

extern char D_00769D20[];
void func_00422888(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            *(s32 *)D_00769D20 = func_0041F810();
        }
    }
}
