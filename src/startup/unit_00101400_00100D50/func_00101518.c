/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001075C8();                            /* extern */
s32 func_004A84B8();                            /* extern */
s32 func_004DFA98(s32);                     /* extern */
s32 func_004FD6C8();                            /* extern */
s32 func_00503F48(s32, s32, s32);       /* extern */

void func_00101518(s32 arg0) {
    func_001075C8();
    func_004DFA98(5);
    func_004FD6C8();
    func_004A84B8();
    func_00503F48(arg0, 0, 0);
}
