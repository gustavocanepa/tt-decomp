#include "types.h"

extern void *D_005D14A8;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);
extern "C" void *func_0035E910(void *);
extern "C" void *AutomaticFader__fadein(void *, float);

struct RaceRankDisplay__structor_1_arg0 {
    char pad0[0x14];
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
};

extern "C" void RaceRankDisplay__structor_1(void *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    ((struct RaceRankDisplay__structor_1_arg0 *)arg0)->unk18 = 0x0;
    ((struct RaceRankDisplay__structor_1_arg0 *)arg0)->unk1C = 0x0;
    ((struct RaceRankDisplay__structor_1_arg0 *)arg0)->unk14 = &D_005D14A8;
    ((struct RaceRankDisplay__structor_1_arg0 *)arg0)->unk20 = 0x0;
    func_0035E910((char *)arg0 + 0x24);
    AutomaticFader__fadein((char *)arg0 + 0x24, 0.0f); return;
}
