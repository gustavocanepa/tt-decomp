/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A180();                            /* extern */
s32 func_0045F408(void *, s32);                 /* extern */
s32 func_004759D0();                                /* extern */

extern char D_00586EF4[];
struct func_0043A568_arg0 {
    char pad0[0x14];
    s32 unk14;
};
struct func_0043A568_temp_s1 {
    char pad0[0x5C];
    s32 unk5C;
};

void func_0043A568(struct func_0043A568_arg0 *arg0, s32 arg1) {
    struct func_0043A568_temp_s1 *temp_s1;

    if (arg0->unk14 == 0) {
        func_0043A180();
    }
    temp_s1 = *(void **)(s32)D_00586EF4;
    temp_s1->unk5C = func_004759D0();
    func_0045F408(*(void **)(s32)D_00586EF4, arg1);
}
