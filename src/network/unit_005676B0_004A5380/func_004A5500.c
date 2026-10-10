#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0();                            /* extern */

struct func_004A5500_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_004A5500(struct func_004A5500_arg0 *arg0) {
    func_004AE9C0();
    arg0->unk30 = -1;
}
