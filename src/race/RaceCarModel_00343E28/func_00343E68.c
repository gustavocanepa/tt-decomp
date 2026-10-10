/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00343F40(s32, s32);                    /* extern */
s32 func_004A45D0(s32);                         /* extern */
s32 func_0050E1A8(void *);                      /* extern */

struct func_00343E68_arg1 {
    char pad0[0x94];
    s32 unk94;
};
struct func_00343E68_arg0 {
    char pad0[0x100];
    s32 unk100;
};

void func_00343E68(struct func_00343E68_arg0 *arg0, struct func_00343E68_arg1 *arg1) {
    s32 temp_s0;

    temp_s0 = arg1->unk94;
    func_00343F40(arg0->unk100, temp_s0);
    func_004A45D0(temp_s0);
    func_0050E1A8(arg0);
}
