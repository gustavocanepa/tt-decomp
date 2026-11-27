#include "types.h"

struct Obj {
    char pad0[0x468];
    s32 arr[(0x470 - 0x468) / 4];
    s32 unk458;
};

extern "C" void RaceBattleInformationT_2__addEnemy(Obj *arg0, s32 arg1) {
    s32 *ctr = &arg0->unk458;
    s32 idx = *ctr;
    arg0->arr[idx] = arg1;
    *ctr = idx + 1;
}
