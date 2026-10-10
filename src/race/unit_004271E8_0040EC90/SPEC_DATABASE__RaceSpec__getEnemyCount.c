#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0040EE68(void *, s64);
struct func_0040EF58_arg0 {
    char pad0[0xA0];
    s64 unkA0;
    char padA8[0x8];
    s32 *unkB0;
};

s32 SPEC_DATABASE__RaceSpec__getEnemyCount(struct func_0040EF58_arg0 *arg0) {
    if (arg0->unkB0 == NULL) {
        if (func_0040EE68(arg0, arg0->unkA0) != 0) {
            goto block_6;
        }
        return -1;
    }
block_6:
    return *arg0->unkB0;
}
