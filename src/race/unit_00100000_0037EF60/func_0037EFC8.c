/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 ResultLicense__init();                            /* extern */
s32 func_0037FCE0(void *);                      /* extern */

struct func_0037EFC8_arg0 {
    char pad0[0x874];
    f32 unk874;
    char pad878[0x4];
    s32 unk87C;
    s32 unk880;
    char pad884[0xAC];
    s32 unk930;
    s32 unk934;
};

void func_0037EFC8(struct func_0037EFC8_arg0 *arg0) {
    ResultLicense__init();
    arg0->unk87C = 0;
    arg0->unk874 = 0x1.0000000000000p+0f;
    arg0->unk880 = 0;
    arg0->unk930 = 0;
    arg0->unk934 = 0;
    func_0037FCE0(arg0);
}
