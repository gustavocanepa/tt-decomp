/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AEB30(s32);                         /* extern */
s32 func_004A5668(s32);                         /* extern */
s32 func_004A5880(s32);                         /* extern */

struct func_00102820_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00102820(void *arg0) {
    ((struct func_00102820_arg0 *)arg0)->unk4 = 0;
    func_004AEB30(arg0 + 8);
    func_004A5668(((struct func_00102820_arg0 *)arg0)->unk0);
    func_004A5880(((struct func_00102820_arg0 *)arg0)->unk0);
}
