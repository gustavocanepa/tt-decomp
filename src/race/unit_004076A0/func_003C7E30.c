#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00412368(s32);                         /* extern */

struct func_003C7E30_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_003C7E30(void *arg0) {
    func_00412368(arg0 + 0xB0);
    ((struct func_003C7E30_arg0 *)arg0)->unkA8 = 0;
}
