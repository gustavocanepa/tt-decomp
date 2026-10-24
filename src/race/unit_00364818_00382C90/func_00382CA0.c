#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00452918(s32);                         /* extern */

struct func_00382CA0_arg0 {
    char pad0[0x50];
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

void func_00382CA0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    func_00452918(arg0 + 0x3C);
    ((struct func_00382CA0_arg0 *)arg0)->unk50 = fparg0;
    ((struct func_00382CA0_arg0 *)arg0)->unk54 = fparg1;
    ((struct func_00382CA0_arg0 *)arg0)->unk58 = fparg2;
}
