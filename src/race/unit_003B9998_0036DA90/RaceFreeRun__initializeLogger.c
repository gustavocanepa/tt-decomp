#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002FDBA8(s32, s32);                /* extern */
void *func_00386980(void *);                        /* extern */
s32 RaceSolitaire__initializeLogger();                            /* extern */

struct RaceFreeRun__virtual_152_arg0 {
    char pad0[0x70];
    s32 unk70;
};

s32 RaceFreeRun__initializeLogger(struct RaceFreeRun__virtual_152_arg0 *arg0) {
    RaceSolitaire__initializeLogger();
    func_002FDBA8(arg0->unk70, 0);
    if (M2C_FIELD(func_00386980(arg0), s32 *, 0x1D0) == 0) {
        func_002FDBA8(arg0->unk70, 1);
    }
}
