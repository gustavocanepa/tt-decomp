/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00320D70(void *, f32);                 /* extern */
s32 func_00475780(f32);                         /* extern */

struct func_002CA428_arg0 {
    char pad0[0x1044];
    f32 unk1044;
};

void func_002CA428(struct func_002CA428_arg0 *arg0, f32 fparg0) {
    func_00475780(arg0->unk1044);
    func_00320D70(arg0, fparg0);
}
