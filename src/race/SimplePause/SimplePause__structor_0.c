#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00377FE0(void *);                      /* extern */
s32 func_00377E78();                            /* extern */

extern char D_005D3AF8[];
struct SimplePause__structor_0_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void SimplePause__structor_0(struct SimplePause__structor_0_arg0 *arg0) {
    func_00377E78();
    arg0->unk8 = (s32)D_005D3AF8;
    func_00377FE0(arg0);
}
