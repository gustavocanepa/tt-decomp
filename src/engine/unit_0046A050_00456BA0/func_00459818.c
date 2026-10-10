#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00459878();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA208[];
struct func_00459818_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_00459818(struct func_00459818_arg0 *arg0, s32 arg1) {
    arg0->unk24 = (s32)D_005DA208;
    func_00459878();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
