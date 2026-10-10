#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003216C0();                            /* extern */

extern char D_005D6E78[];
struct func_003AC058_arg0 {
    s32 unk0;
    char pad4[0x194];
    s32 unk198;
};

void func_003AC058(struct func_003AC058_arg0 *arg0) {
    func_003216C0();
    arg0->unk198 = 0;
    arg0->unk0 = (s32)D_005D6E78;
}
