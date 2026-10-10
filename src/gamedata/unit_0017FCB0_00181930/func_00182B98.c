#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00182A18();                            /* extern */
s32 func_001A6AA8(s32);                         /* extern */

struct func_00182B98_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

void func_00182B98(struct func_00182B98_arg0 *arg0) {
    func_00182A18();
    func_001A6AA8(arg0->unkB4);
}
