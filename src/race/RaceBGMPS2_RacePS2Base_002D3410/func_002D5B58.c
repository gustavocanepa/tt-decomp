/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00470450(s32);                     /* extern */
s32 func_00470B48(s32);                         /* extern */
s32 func_00470E60(s32);                     /* extern */

void func_002D5B58(s32 arg0) {
    func_00470450(0xFF000000);
    func_00470B48(arg0);
    func_00470E60(1);
    func_00470450(-1);
}
