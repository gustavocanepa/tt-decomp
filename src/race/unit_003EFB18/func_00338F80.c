#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0037A800();                            /* extern */

extern char D_005CBC28[];
struct func_00338F80_arg0 {
    char pad0[0x134];
    s32 unk134;
};

void func_00338F80(struct func_00338F80_arg0 *arg0) {
    func_0037A800();
    arg0->unk134 = (s32)D_005CBC28;
}
