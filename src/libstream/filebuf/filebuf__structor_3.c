#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 streambuf__structor_1(void *, s32);             /* extern */
s32 func_004EC2C8(void *, s32, s32);                    /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DB490[];
struct filebuf__structor_3_arg0_unk50 {
    char pad0[0x84];
    s32 (*unk84)(void *);
};
struct filebuf__structor_3_arg0 {
    s32 unk0;
    char pad4[0xC];
    s32 unk10;
    s32 unk14;
    char pad18[0x20];
    s32 unk38;
    char pad3C[0x14];
    struct filebuf__structor_3_arg0_unk50 *unk50;
};

void filebuf__structor_3(struct filebuf__structor_3_arg0 *arg0, s32 arg1) {
    s32 temp_a1;

    arg0->unk50 = (void *)(s32)D_005DB490;
    if (arg0->unk38 >= 0) {
        temp_a1 = arg0->unk10;
        func_004EC2C8(arg0, temp_a1, arg0->unk14 - temp_a1);
        if (!(arg0->unk0 & 0x40)) {
            arg0->unk50->unk84(arg0);
        }
    }
    streambuf__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
