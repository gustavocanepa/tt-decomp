#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00480F20();                            /* extern */
s32 func_0047A0D8(s32);                         /* extern */
s32 func_0047BE70(void *);                      /* extern */

extern char D_005DA2E0[];
struct func_0047A250_temp_s2 {
    char pad0[0xC];
    s32 unkC;
};

struct func_0047A250_arg0 {
    char pad0[0xA4];
    s32 unkA4;
    char padA8[0x44];
    s32 unkEC;
};

void func_0047A250(void *arg0) {
    s32 temp_s1;
    struct func_0047A250_temp_s2 *temp_s2;

    temp_s1 = arg0 + 0xE8;
    temp_s2 = arg0 + 0xC4;
    func_00480F20();
    ((struct func_0047A250_arg0 *)arg0)->unkA4 = (s32)D_005DA2E0;
    func_0047BE70(temp_s2);
    func_0047A0D8(temp_s1);
    ((struct func_0047A250_arg0 *)arg0)->unkEC = 0;
    temp_s2->unkC = temp_s1;
}
