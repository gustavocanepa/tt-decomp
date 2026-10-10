#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004CC568(s32);                     /* extern */
s32 func_004CC668(s32);                     /* extern */
s32 func_004CCE98();                            /* extern */

void func_004CCD70(void) {
    func_004CC568(1);
    func_004CC568(5);
    func_004CC568(6);
    func_004CC668(1);
    func_004CC568(6);
    func_004CC568(6);
    func_004CC568(1);
    func_004CC568(1);
    func_004CCE98();
}
