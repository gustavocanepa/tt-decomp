#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00370880(s32);                         /* extern */
s32 func_00370A58(s32);                         /* extern */
s32 func_0037BCE8(s32);                         /* extern */

struct func_00369610_arg0 {
    char pad0[0x12B0];
    s32 unk12B0;
    s32 unk12B4;
};

s32 func_00369610(void *arg0, s32 arg1) {
    func_00370A58(arg0 + 0x20);
    func_00370880(arg0 + 0x1264);
    ((struct func_00369610_arg0 *)arg0)->unk12B4 = 0;
    ((struct func_00369610_arg0 *)arg0)->unk12B0 = 0x157529FF;
    if (arg1 == 0) {
        func_0037BCE8(arg0 + 0x12A8);
    }
}
