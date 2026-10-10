#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FF3A8(s32 *, s32);              /* extern */
s32 func_004037A8(void *, s32);             /* extern */
s32 func_00403F68(void *, s32);             /* extern */
s32 func_004042A8(void *, s32);             /* extern */
s32 func_004046C0(s32, s32);                /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

extern char D_005D9500[];
void func_00402A90(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_005D9500;
    func_004046C0(arg0 + 0x23, 2);
    func_004042A8(arg0 + 0x19, 2);
    func_00403F68(arg0 + 0x12, 2);
    func_004037A8(arg0 + 0x6, 2);
    func_003FF3A8(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
