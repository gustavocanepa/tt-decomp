#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004CC568(s32);                         /* extern */
s32 func_004CC668(s32);                     /* extern */

void func_004CD080(void) {
    func_004CC568(3);
    if (func_004CC568(1) != 0) {
        func_004CC568(8);
        func_004CC568(8);
        func_004CC568(8);
    }
    func_004CC568(0xE);
    func_004CC668(1);
    func_004CC568(0xE);
}
