#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00416E68();                            /* extern */

extern char D_005C91B0[];
struct func_00552088_arg0 {
    s32 unk0;
    char pad4[0x88];
    s32 unk8C;
    s32 unk90;
};

void func_00552088(struct func_00552088_arg0 *arg0) {
    func_00416E68();
    arg0->unk90 = 0;
    arg0->unk8C = 0;
    arg0->unk0 = (s32)D_005C91B0;
}
