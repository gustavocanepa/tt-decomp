#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FF398();                            /* extern */
s32 func_00403750(s32);                         /* extern */
s32 func_00403F10(void *);                      /* extern */
s32 func_00404250(void *);                      /* extern */
s32 func_00404660(void *);                      /* extern */

extern char D_005D9500[];
void func_00402A40(s32 *arg0) {
    func_003FF398();
    *arg0 = (s32)D_005D9500;
    func_00403750(arg0 + 0x6);
    func_00403F10(arg0 + 0x12);
    func_00404250(arg0 + 0x19);
    func_00404660(arg0 + 0x23);
}
