/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00416BF8(f32, f32, f32);               /* extern */

struct func_00566550_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_00566550(s32 arg0, struct func_00566550_arg1 *arg1) {
    func_00416BF8(arg1->unk0, arg1->unk4, arg1->unk8);
}
