#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00259198(s32);                         /* extern */

struct func_001F2720_arg0 {
    char pad0[0x110];
    s32 unk110;
    char pad114[0x18];
    s32 unk12C;
    char pad130[0xC];
    s32 unk13C;
    s32 unk140;
    s32 unk144;
};

void func_001F2720(struct func_001F2720_arg0 *arg0) {
    arg0->unk110 = 0;
    func_00259198(arg0->unk12C);
    if (arg0->unk13C != 0) {
        arg0->unk140 = 1;
        return;
    }
    arg0->unk144 = 1;
}
