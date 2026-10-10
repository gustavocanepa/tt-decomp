#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AC580(s32);                         /* extern */

struct func_00283058_arg0 {
    char pad0[0x110];
    f32 unk110;
};

void func_00283058(void *arg0, s32 arg1) {
    func_004AC580(arg0 + 0xE8);
    ((struct func_00283058_arg0 *)arg0)->unk110 = (f32) arg1;
}
