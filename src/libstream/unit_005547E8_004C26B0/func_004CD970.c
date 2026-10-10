/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CC5A8(s32);                         /* extern */
s32 func_004CC668(s32);                     /* extern */
s32 func_004CCC78();                            /* extern */
s32 func_004CCE70();                            /* extern */
s32 func_004CF8C8();                                /* extern */

extern char D_005A07F0[];
s32 func_004CD970(s32 *arg0, s32 *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    func_004CCC78();
    temp_v0 = func_004CC5A8(0x20);
    if ((u32) (temp_v0 - 0x101) >= 0xAFU) {
        func_004CC668(0x20);
        return -1;
    }
    func_004CC668(0x20);
    func_004CCE70();
    temp_v0_2 = func_004CF8C8();
    *arg1 = temp_v0_2;
    *arg0 = ((((temp_v0 & 0xFF) - 1) * *(s32 *)D_005A07F0) + temp_v0_2) - 1;
    *arg1 = 1;
    return 1;
}
