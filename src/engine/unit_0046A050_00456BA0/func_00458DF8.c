#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004587A0(void *);                      /* extern */
s32 func_00459A38(s32);                             /* extern */

struct func_00458DF8_arg0 {
    char pad0[0xAE0];
    s32 unkAE0;
};

void func_00458DF8(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0xA88;
    func_00459A38(temp_s1);
    ((struct func_00458DF8_arg0 *)arg0)->unkAE0 = func_00459A38(temp_s1);
    func_004587A0(arg0);
}
