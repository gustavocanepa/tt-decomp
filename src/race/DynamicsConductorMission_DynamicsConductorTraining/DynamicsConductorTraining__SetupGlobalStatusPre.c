#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F0D98();                            /* extern */

struct DynamicsConductorMission__virtual_25_arg0 {
    char pad0[0x2392C];
    s8 unk2392C;
};

void DynamicsConductorTraining__SetupGlobalStatusPre(struct DynamicsConductorMission__virtual_25_arg0 *arg0) {
    arg0->unk2392C = 0;
    func_002F0D98();
}
