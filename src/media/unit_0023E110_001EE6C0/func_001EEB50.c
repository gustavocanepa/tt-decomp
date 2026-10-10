/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00266268(s32, s32);                    /* extern */
s32 func_004A8268(s32, s32);                    /* extern */

extern char D_005EA5F8[];
struct func_001EEB50_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_001EEB50(struct func_001EEB50_arg0 *arg0, s32 arg1) {
    if (func_004A8268(arg1, (s32)D_005EA5F8) != 0) {
        func_00266268(arg0->unk10, arg1);
    }
}
