#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0037FAA0();                            /* extern */

extern char D_005D4500[];
struct func_0037EF28_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x914];
    s32 unk930;
    s32 unk934;
};

void func_0037EF28(struct func_0037EF28_arg0 *arg0) {
    func_0037FAA0();
    arg0->unk934 = 0;
    arg0->unk930 = 0;
    arg0->unk18 = (s32)D_005D4500;
}
