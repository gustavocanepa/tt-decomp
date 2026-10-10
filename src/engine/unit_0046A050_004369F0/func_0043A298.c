/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00467728(void *);                      /* extern */
s32 func_0046AC48(s32);                         /* extern */

struct func_0043A298_arg1 {
    char pad0[0x18];
    s32 unk18;
};

void func_0043A298(s32 arg0, struct func_0043A298_arg1 *arg1) {
    func_00467728(arg1);
    func_0046AC48(arg1->unk18);
}
