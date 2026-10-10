/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0078C400[];
s32 func_004FD400(s32 arg0) {
    return *(s32 *)((s32)D_0078C400 + (arg0 * 4));
}
