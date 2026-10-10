/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0034C5E8(void *);                          /* extern */
s32 func_0034D250();                            /* extern */
s32 func_0041F700(s32, s32);                    /* extern */

struct func_0034C868_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

void func_0034C868(struct func_0034C868_arg0 *arg0) {
    func_0034D250();
    if (arg0->unk8C != 0) {
        func_0041F700(arg0->unk8C, func_0034C5E8(arg0));
    }
}
