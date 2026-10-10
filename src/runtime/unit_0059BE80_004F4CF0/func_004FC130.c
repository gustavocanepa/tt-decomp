/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FC048();                     /* extern */

void func_004FC130(s32 arg0) {
    if (arg0 == 0xA) {
        func_004FC048(0xD);
        func_004FC048(0xA);
        return;
    }
    func_004FC048();
}
