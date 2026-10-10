#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047E910();                            /* extern */
s32 func_0056DF88(s32);                         /* extern */

extern char D_005DA640[];
struct func_0047E588_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_0047E588(void *arg0) {
    func_0047E910();
    ((struct func_0047E588_arg0 *)arg0)->unkA8 = (s32)D_005DA640;
    func_0056DF88(arg0 + 0xAC);
}
