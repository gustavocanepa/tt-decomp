/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0031ABB0(s32);                         /* extern */
s32 func_0031ABD0(s32);                         /* extern */
s32 func_0031ABF0(s32, s32, s32);       /* extern */
s32 func_0031CF30(s32, s32);                    /* extern */
s32 func_002D7EF8();                                /* extern */

struct func_002D8388_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
    char pad6C[0x28];
    s32 unk94;
    s32 unk98;
};

void func_002D8388(struct func_002D8388_arg0 *arg0, s32 arg1) {
    s32 temp_a0;

    if (func_002D7EF8() != 0) {
        if (arg0->unk68 != 0) {
            func_0031CF30(arg1, arg0->unk64);
        }
        if (arg0->unk98 != 0) {
            temp_a0 = arg0->unk94;
            switch (temp_a0) {                      /* irregular */
            case 0:
                func_0031ABB0(arg1);
                func_0031ABF0(arg1, 0, 0);
                break;
            case 1:
                func_0031ABB0(arg1);
                func_0031ABF0(arg1, 0, 1);
                break;
            case 2:
                func_0031ABD0(arg1);
                break;
            }
        }
    }
}
