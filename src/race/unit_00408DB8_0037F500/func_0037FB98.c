#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0037D460(void *, s32);             /* extern */
s32 func_00380458();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D4678[];
struct func_0037FB98_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_0037FB98(struct func_0037FB98_arg0 *arg0, s32 arg1) {
    arg0->unk18 = (s32)D_005D4678;
    func_00380458();
    func_0037D460(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
