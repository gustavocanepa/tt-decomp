#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004369B8(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005C9468[];
struct DynamicsConductor__structor_1_arg0 {
    char pad0[0x241CC];
    s32 unk241CC;
};

void DynamicsConductor__structor_1(void *arg0, s32 arg1) {
    ((struct DynamicsConductor__structor_1_arg0 *)arg0)->unk241CC = (s32)D_005C9468;
    func_004369B8(arg0 + 0x218AC, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
