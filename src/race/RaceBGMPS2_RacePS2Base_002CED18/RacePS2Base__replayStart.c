#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033C760();                            /* extern */

struct RacePS2Base__virtual_43_arg0 {
    char pad0[0xD004];
    f32 unkD004;
};

void RacePS2Base__replayStart(struct RacePS2Base__virtual_43_arg0 *arg0) {
    func_0033C760();
    if (arg0->unkD004 == 0x0.0p+0f) {
        arg0->unkD004 = 0x1.0000000000000p+0f;
    }
}
