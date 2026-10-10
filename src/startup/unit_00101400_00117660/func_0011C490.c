/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AEAC0(s32);                         /* extern */
s32 func_004AEB30(void *);                      /* extern */

struct func_0011C490_arg0 {
    char pad0[0x2A4];
    s32 unk2A4;
    s32 unk2A8;
    s32 unk2AC;
    s32 unk2B0;
};

void func_0011C490(void *arg0) {
    ((struct func_0011C490_arg0 *)arg0)->unk2A4 = 1;
    ((struct func_0011C490_arg0 *)arg0)->unk2A8 = 0;
    ((struct func_0011C490_arg0 *)arg0)->unk2AC = 0;
    ((struct func_0011C490_arg0 *)arg0)->unk2B0 = 0;
    func_004AEAC0(arg0 + 0x18);
    func_004AEB30(arg0 + 0x48);
}
