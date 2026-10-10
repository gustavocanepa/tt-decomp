#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003748D0();                            /* extern */
s32 func_003CC818(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D3A10[];
struct func_00374390_arg0 {
    char pad0[0xDEC];
    s32 unkDEC;
};

void func_00374390(void *arg0, s32 arg1) {
    ((struct func_00374390_arg0 *)arg0)->unkDEC = (s32)D_005D3A10;
    func_003748D0();
    func_003CC818(arg0 + 0xDF0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
