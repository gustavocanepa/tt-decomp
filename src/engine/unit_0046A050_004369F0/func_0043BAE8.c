#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004452E8();                            /* extern */
s32 func_00445480(s32);                         /* extern */

struct func_0043BAE8_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_0043BAE8(void *arg0) {
    func_004452E8();
    func_00445480(arg0 + 0x18);
    ((struct func_0043BAE8_arg0 *)arg0)->unk20 = 0;
}
