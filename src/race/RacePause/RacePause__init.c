#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00377F28();                            /* extern */
s32 func_0043BB88(void *, s32, s32, s32);   /* extern */
s32 func_0043C9C8(void *, s32, void *);     /* extern */
void *exception__structor_0(s32);                       /* extern */

extern char D_00377500[];
struct RacePause__virtual_01_arg0_unk14 {
    char pad0[0x10];
    s32 unk10;
};
struct RacePause__virtual_01_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    struct RacePause__virtual_01_arg0_unk14 *unk14;
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
    s32 unk24;
};

void RacePause__init(struct RacePause__virtual_01_arg0 *arg0) {
    void *temp_v0;

    func_00377F28();
    arg0->unkC = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    if (arg0->unk10 != 0) {
        temp_v0 = exception__structor_0(0x19C);
        func_0043BB88(temp_v0, arg0->unk10, 0, arg0->unk18);
        arg0->unk14 = temp_v0;
        func_0043C9C8(temp_v0, (s32)D_00377500, arg0);
        arg0->unk14->unk10 = 1;
    }
}
