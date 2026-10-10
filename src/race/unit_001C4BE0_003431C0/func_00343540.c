/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003748D0(void *);                      /* extern */
s32 func_00388FB0(s32);                         /* extern */

struct func_00343540_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    char pad14[0x353C];
    s32 unk3550;
    s32 unk3554;
};

void func_00343540(void *arg0) {
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = ((struct func_00343540_arg0 *)arg0)->unk10;
    if (temp_v0 != 0) {
        func_00388FB0(temp_v0);
        ((struct func_00343540_arg0 *)arg0)->unk10 = 0;
    }
    temp_a0 = ((struct func_00343540_arg0 *)arg0)->unkC;
    if (temp_a0 != 0) {
        func_00388FB0(temp_a0);
        ((struct func_00343540_arg0 *)arg0)->unkC = 0;
    }
    ((struct func_00343540_arg0 *)arg0)->unk3550 = 0;
    ((struct func_00343540_arg0 *)arg0)->unk3554 = 0;
    func_003748D0(arg0 + 0x620);
    func_003748D0(arg0 + 0x1DB0);
}
