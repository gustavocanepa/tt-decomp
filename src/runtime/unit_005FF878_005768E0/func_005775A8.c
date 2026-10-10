#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005524A8(s32, s32);                    /* extern */

struct func_005775A8_arg0 {
    s32 unk0;
    char pad4[0x8];
    s32 unkC;
    s32 unk10;
};

void func_005775A8(struct func_005775A8_arg0 *arg0) {
    func_005524A8(arg0->unkC, arg0->unk0 * arg0->unk10);
}
