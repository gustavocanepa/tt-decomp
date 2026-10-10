#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C9F30(s32 *, s32);              /* extern */
s32 func_004AE9F0(void *, s32);             /* extern */
s32 func_004AC8B8(s32, void *);                 /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

extern char D_005DB158[];
extern char D_005987D8[];
void func_004BFC88(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_005DB158;
    func_004AC8B8(*(s32 *)D_005987D8, arg0 + 1);
    func_004AE9F0(arg0 + 4, 2);
    func_004C9F30(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
