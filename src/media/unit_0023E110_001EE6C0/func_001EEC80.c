/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001EECC0();                            /* extern */
s32 func_00266330(s32, s32);                    /* extern */

struct func_001EEC80_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_001EEC80(struct func_001EEC80_arg0 *arg0, s32 arg1) {
    func_001EECC0();
    func_00266330(arg0->unk10, arg1);
}
