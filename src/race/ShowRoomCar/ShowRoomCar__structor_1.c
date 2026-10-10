#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005C9630[];
struct ShowRoomCar__structor_1_arg0 {
    s32 unk0;
    s8 unk4;
    char pad5[0x3];
    s32 unk8;
};

void ShowRoomCar__structor_1(struct ShowRoomCar__structor_1_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk8 = (s32)D_005C9630;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
    }
    arg0->unk4 = 0;
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
