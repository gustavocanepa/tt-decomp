#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004395C0(s32, f32);                /* extern */

extern char D_005865D0[];
struct func_002F8A18_arg0 {
    char pad0[0x5E4];
    f32 unk5E4;
};

void func_002F8A18(struct func_002F8A18_arg0 *arg0) {
    func_004395C0((s32)D_005865D0, arg0->unk5E4);
}
