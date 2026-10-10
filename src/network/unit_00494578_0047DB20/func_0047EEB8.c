#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047E910();                            /* extern */
s32 func_0047EFA8(void *);                      /* extern */
s32 func_0047F518(s32);                         /* extern */

extern char D_005DA6F0[];
struct func_0047EEB8_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_0047EEB8(void *arg0) {
    func_0047E910();
    ((struct func_0047EEB8_arg0 *)arg0)->unkA8 = (s32)D_005DA6F0;
    func_0047F518(arg0 + 0xB0);
    func_0047EFA8(arg0);
}
