#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void AutomobileControl__clearPacket(s32);                         /* extern */

struct func_002E7BE0_arg0 {
    s32 unk0;
    s32 unk4;
    s8 unk8;
    char pad9[0x3];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    char pad18[0x20];
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

void func_002E7BE0(void *arg0) {
    ((struct func_002E7BE0_arg0 *)arg0)->unk8 = 0;
    ((struct func_002E7BE0_arg0 *)arg0)->unkC = 0;
    ((struct func_002E7BE0_arg0 *)arg0)->unk4 = (s32) ((struct func_002E7BE0_arg0 *)arg0)->unk0;
    ((struct func_002E7BE0_arg0 *)arg0)->unk3C = 0;
    ((struct func_002E7BE0_arg0 *)arg0)->unk38 = 0;
    ((struct func_002E7BE0_arg0 *)arg0)->unk40 = 0;
    ((struct func_002E7BE0_arg0 *)arg0)->unk44 = 0;
    ((struct func_002E7BE0_arg0 *)arg0)->unk14 = 0;
    AutomobileControl__clearPacket(arg0 + 0x18);
    if (((struct func_002E7BE0_arg0 *)arg0)->unk48 == 0) {
        ((struct func_002E7BE0_arg0 *)arg0)->unk38 = 1;
    }
}
