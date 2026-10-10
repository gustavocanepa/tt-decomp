#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047E910(s32);                         /* extern */
s32 func_0047EFF0();                            /* extern */

extern char D_005DA748[];
struct func_0047F748_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_0047F748(void *arg0) {
    func_0047EFF0();
    ((struct func_0047F748_arg0 *)arg0)->unk20 = (s32)D_005DA748;
    func_0047E910(arg0 + 0x24);
}
