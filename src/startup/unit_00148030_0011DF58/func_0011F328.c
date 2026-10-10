#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020B378();                            /* extern */

struct func_0011F328_arg0 {
    char pad0[0xB4];
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    char padC0[0x4];
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
};

void func_0011F328(struct func_0011F328_arg0 *arg0) {
    func_0020B378();
    arg0->unkB4 = 0;
    arg0->unkB8 = 0;
    arg0->unkBC = 0;
    arg0->unkC4 = 0;
    arg0->unkC8 = 0;
    arg0->unkCC = 0;
    arg0->unkD0 = 0;
}
