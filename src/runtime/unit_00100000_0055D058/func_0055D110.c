#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0037D418();                            /* extern */

extern char D_005D45D0[];
struct func_0055D110_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x850];
    s32 unk86C;
};

void func_0055D110(struct func_0055D110_arg0 *arg0) {
    func_0037D418();
    arg0->unk86C = 0;
    arg0->unk18 = (s32)D_005D45D0;
}
