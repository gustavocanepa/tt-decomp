/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A080(s32, s32, s32, s32, s32); /* extern */
s32 func_0043A150(s32, s32, s32, s32); /* extern */
s32 func_0043A168(s32, s32, s32, s32); /* extern */

struct func_0043B320_arg0 {
    char pad0[0x6E14];
    s32 unk6E14;
    char pad6E18[0x1C];
    s32 unk6E34;
};

void func_0043B320(struct func_0043B320_arg0 *arg0) {
    arg0->unk6E34 = 0;
    func_0043A168(arg0->unk6E14, 0, 0, 0);
    func_0043A150(arg0->unk6E14, 3, 0x80, 0xFF);
    func_0043A080(arg0->unk6E14, 1, 1, 1, 1);
}
