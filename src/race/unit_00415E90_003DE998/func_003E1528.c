/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003E6238(s32, f32, f32, f32);          /* extern */

struct func_003E1528_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_003E1528(void *arg0) {
    func_003E6238(arg0 + 0x10, ((struct func_003E1528_arg0 *)arg0)->unk0, ((struct func_003E1528_arg0 *)arg0)->unk4, ((struct func_003E1528_arg0 *)arg0)->unk8);
}
