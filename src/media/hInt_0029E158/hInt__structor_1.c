#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7650();                            /* extern */

extern char D_005C47F8[];
struct hInt__structor_1_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
};
struct hInt__structor_1_arg1 {
    char pad0[0x10];
    s32 unk10;
};

s32 hInt__structor_1(struct hInt__structor_1_arg0 *arg0, struct hInt__structor_1_arg1 *arg1) {
    func_002A7650();
    arg0->unk4 = (s32)D_005C47F8;
    arg0->unk10 = (s32) arg1->unk10;
}
