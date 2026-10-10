/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00439AD8(s32, s32, s32, s32, s32); /* extern */

struct func_0044C2D8_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 unkC;
};

void func_0044C2D8(struct func_0044C2D8_arg0 *arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk8;
    func_00439AD8(arg0->unk0, (s32) ((s32) (arg0->unkC - temp_v1) >> 2) / 6, temp_v1, 0, 0);
}
