#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045BF58();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA250[];
struct func_0045BEF8_arg0 {
    char pad0[0x84C];
    s32 unk84C;
};

void func_0045BEF8(struct func_0045BEF8_arg0 *arg0, s32 arg1) {
    arg0->unk84C = (s32)D_005DA250;
    func_0045BF58();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
