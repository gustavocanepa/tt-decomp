#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0035E778(void *);                      /* extern */
s32 func_0035E910(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D1070[];
struct func_0035B948_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

void func_0035B948(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct func_0035B948_arg0 *)arg0)->unk18 = 0;
    ((struct func_0035B948_arg0 *)arg0)->unk1C = 0;
    ((struct func_0035B948_arg0 *)arg0)->unk14 = (s32)D_005D1070;
    ((struct func_0035B948_arg0 *)arg0)->unk20 = 0;
    ((struct func_0035B948_arg0 *)arg0)->unk24 = 0;
    ((struct func_0035B948_arg0 *)arg0)->unk28 = 0;
    func_0035E910(arg0 + 0x2C);
    func_0035E778(arg0 + 0x48);
}
