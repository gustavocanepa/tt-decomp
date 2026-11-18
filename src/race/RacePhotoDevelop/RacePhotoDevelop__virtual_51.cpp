#include "types.h"

extern "C" s32 RaceBase__getDefaultCarModelType(void *arg0);

struct Obj003C8BC0 {
    char pad0[0x447A0];
    s32 unk2EF30;
};

extern "C" s32 RacePhotoDevelop__virtual_51(struct Obj003C8BC0 *arg0) {
    if (arg0->unk2EF30 != 0) {
        return 4;
    }
    return RaceBase__getDefaultCarModelType(arg0);
}
