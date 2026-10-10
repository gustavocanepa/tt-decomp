/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004088C8(void *, s32, s32, s32);   /* extern */
s32 func_00408B58();                                /* extern */
s32 func_0040D420(s32);                             /* extern */

struct func_00408888_arg0 {
    char pad0[0x4E8];
    s32 unk4E8;
};

void func_00408888(struct func_00408888_arg0 *arg0) {
    func_004088C8(arg0, 0, func_0040D420(func_00408B58()), arg0->unk4E8);
}
