/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A5018();                            /* extern */
s32 func_004A5088(void *);                      /* extern */

struct func_004AEB68_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_004AEB68(struct func_004AEB68_arg0 *arg0) {
    func_004A5018();
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    func_004A5088(arg0);
}
