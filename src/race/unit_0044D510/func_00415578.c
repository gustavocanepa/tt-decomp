/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045F710(s32);                         /* extern */

extern char D_00586EF4[];
void func_00415578(s32 *arg0) {
    if (*arg0 != 0) {
        *arg0 = 0;
        func_0045F710(*(s32 *)D_00586EF4);
    }
}
