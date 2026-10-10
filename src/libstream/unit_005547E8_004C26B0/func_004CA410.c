#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CA520(s32, void *);                 /* extern */
s32 func_004CA568(s32, void *);                 /* extern */

struct func_004CA410_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_004CA410(struct func_004CA410_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_004CA568(temp_v0, arg0);
    }
    arg0->unk4 = arg1;
    if (arg1 != 0) {
        func_004CA520(arg1, arg0);
    }
}
