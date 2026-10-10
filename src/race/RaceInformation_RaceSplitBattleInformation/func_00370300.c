#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D26A0[];
void RaceDisplayObjectBase__structor_1(void *, s32);
void func_0050E1A8(void *);
struct func_00370300_arg0 {
    char pad0[0x134];
    s32 unk134;
};

void func_00370300(struct func_00370300_arg0 *arg0, s32 arg1) {
    arg0->unk134 = (s32)D_005D26A0;
    RaceDisplayObjectBase__structor_1(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
