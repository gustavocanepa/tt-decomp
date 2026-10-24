#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK AutomobileControlRecord__Recorder__finish(void *);                      /* extern */
void RaceBasic__cleanup();                            /* extern */

M2C_UNK func_00386CC8(void *arg0) {
    RaceBasic__cleanup();
    if ((u32) M2C_FIELD(arg0, u32 *, 0xD8C) < 2U) {
        AutomobileControlRecord__Recorder__finish(arg0 + 0xF16C);
        AutomobileControlRecord__Recorder__finish(arg0 + 0xF0FC);
    }
}
