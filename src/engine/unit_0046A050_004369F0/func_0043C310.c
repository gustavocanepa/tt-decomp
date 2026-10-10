/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043C348(s32 *);                       /* extern */
s32 func_00446A58(s32, s32 *);                  /* extern */

void func_0043C310(s32 *arg0) {
    func_00446A58(*arg0, arg0);
    func_0043C348(arg0);
}
