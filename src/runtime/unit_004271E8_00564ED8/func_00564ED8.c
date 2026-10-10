#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */

extern char D_005D90A8[];
struct func_00564ED8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_00564ED8(struct func_00564ED8_arg0 *arg0, s32 arg1, s32 arg2) {
    func_00400D68();
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    arg0->unkC = arg2;
    arg0->unk0 = (s32)D_005D90A8;
    arg0->unk10 = 0;
}
