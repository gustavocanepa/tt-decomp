#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_004A4D68();                            /* extern */
s32 func_004A4DD8(void *);                      /* extern */

struct func_0047EE40_arg0 {
    char pad0[0x98];
    s32 unk98;
};

s32 func_0047EE40(struct func_0047EE40_arg0 *arg0) {
    s32 temp_s1;

    func_004A4D68();
    temp_s1 = arg0->unk98;
    arg0->unk98 = 1;
    func_004A4DD8(arg0);
    return temp_s1 ^ 1;
}
