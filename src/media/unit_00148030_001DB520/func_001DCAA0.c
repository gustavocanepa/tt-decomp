/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DC918(s32, s32, s32, s32);          /* extern */
s32 func_001DC9F0(s32, s32, void *);            /* extern */
s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct func_001DCAA0_arg3 {
    char pad0[0x44];
    s32 unk44;
};

void func_001DCAA0(s32 arg0, s32 arg1, s32 arg2, struct func_001DCAA0_arg3 *arg3) {
    s32 temp_s4;

    func_002C0FE8(arg2);
    temp_s4 = arg3->unk44;
    func_001DC9F0(arg0, arg1, arg3);
    func_001DC918(arg0, arg1, arg2, temp_s4);
    func_002C1050(arg2);
}
