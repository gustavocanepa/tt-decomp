#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 AutomobileControlRecord__Recorder__read(void *);                      /* extern */

struct RaceInputLan__virtual_06_arg0 {
    char pad0[0x1D0];
    s32 unk1D0;
};

s32 RaceInput__replayControl(void *arg0) {
    if (((struct RaceInputLan__virtual_06_arg0 *)arg0)->unk1D0 == 0) {
        AutomobileControlRecord__Recorder__read(arg0 + 0xDC);
    }
}
