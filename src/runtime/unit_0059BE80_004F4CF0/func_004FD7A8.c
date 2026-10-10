/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0078C264[];
extern char D_0078C26C[];
void func_004FD7A8(s32 arg0) {
    if (arg0 < 0) {
        *(s32 *)(((arg0 & 0x7FFFFFFF) * 0xC) + *(s32 *)D_0078C264) = 0;
        return;
    }
    *(s32 *)((arg0 * 0xC) + *(s32 *)D_0078C26C) = 0;
}
