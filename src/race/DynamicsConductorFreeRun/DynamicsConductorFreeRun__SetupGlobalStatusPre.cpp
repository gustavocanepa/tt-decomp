extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002F0D98(...) throw();
void DynamicsConductorFreeRun__InitializeLapTimeCorrection(...) throw();

struct DynamicsConductorFreeRun__virtual_25_arg0 {
    char pad0[0x20A28];
    u8 unk20A28;
};

void DynamicsConductorFreeRun__SetupGlobalStatusPre(char *arg0) {
    func_002F0D98();
    DynamicsConductorFreeRun__InitializeLapTimeCorrection(arg0);
    if (((struct DynamicsConductorFreeRun__virtual_25_arg0 *)arg0)->unk20A28 != 0) {
        ((struct DynamicsConductorFreeRun__virtual_25_arg0 *)arg0)->unk20A28 = 2U;
    }
}

}
