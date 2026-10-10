#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0035E910(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005CFC40[];
struct func_00365D88_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s8 unk28;
    char pad29[0x7];
    s8 unk30;
    char pad31[0x7];
    s8 unk38;
};

void func_00365D88(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct func_00365D88_arg0 *)arg0)->unk18 = 0;
    ((struct func_00365D88_arg0 *)arg0)->unk14 = (s32)D_005CFC40;
    func_0035E910(arg0 + 0x40);
    ((struct func_00365D88_arg0 *)arg0)->unk1C = 0;
    ((struct func_00365D88_arg0 *)arg0)->unk20 = 0;
    ((struct func_00365D88_arg0 *)arg0)->unk24 = 0;
    ((struct func_00365D88_arg0 *)arg0)->unk28 = 0;
    ((struct func_00365D88_arg0 *)arg0)->unk30 = 0;
    ((struct func_00365D88_arg0 *)arg0)->unk38 = 0;
}
