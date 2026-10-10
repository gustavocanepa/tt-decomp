#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DB058(s32, void *);                 /* extern */

extern char D_005B0E70[];
struct func_001DBFD8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_001DBFD8(struct func_001DBFD8_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk18 = (s32)D_005B0E70;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    func_001DB058(arg1, arg0);
}
