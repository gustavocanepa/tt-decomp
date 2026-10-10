/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004AEB30(void *);                      /* extern */

struct func_0047FFF0_arg0 {
    char pad0[0x1A80];
    s32 unk1A80;
};

void func_0047FFF0(void *arg0) {
    ((struct func_0047FFF0_arg0 *)arg0)->unk1A80 = 0;
    func_004AEB30(arg0 + 0x1960);
    func_004AEB30(arg0 + 0x19C0);
}
