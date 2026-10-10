#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E4E70();                            /* extern */

struct func_002E4ED8_arg0 {
    char pad0[0x5B0];
    f32 unk5B0;
};

void func_002E4ED8(struct func_002E4ED8_arg0 *arg0, f32 fparg0) {
    arg0->unk5B0 = fparg0;
    func_002E4E70();
}
