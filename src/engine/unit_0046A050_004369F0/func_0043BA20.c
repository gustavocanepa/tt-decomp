#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00445200();                            /* extern */
s32 func_00445310(s32, s32, s32, f32);          /* extern */

struct func_0043BA20_arg0 {
    char pad0[0x20];
    f32 unk20;
};
struct func_0043BA20_arg1 {
    char pad0[0x20];
    f32 unk20;
};
struct func_0043BA20_arg2 {
    char pad0[0x20];
    f32 unk20;
};

void func_0043BA20(void *arg0, void *arg1, void *arg2, f32 fparg0) {
    func_00445200();
    func_00445310(arg0 + 0x18, arg1 + 0x18, arg2 + 0x18, fparg0);
    ((struct func_0043BA20_arg0 *)arg0)->unk20 = (f32) ((((struct func_0043BA20_arg1 *)arg1)->unk20 * (1.0f - fparg0)) + (((struct func_0043BA20_arg2 *)arg2)->unk20 * fparg0));
}
