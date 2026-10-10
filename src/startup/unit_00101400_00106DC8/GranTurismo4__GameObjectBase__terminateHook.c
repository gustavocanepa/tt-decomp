/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004ACC88(s32, void *);                 /* extern */

struct CarIconMaker__virtual_10_temp_a1 {
    char pad0[0xC];
    s32 unkC;
};
struct CarIconMaker__virtual_10_temp_s0 {
    char pad0[0xC];
    s32 unkC;
};

void GranTurismo4__GameObjectBase__terminateHook(s32 arg0) {
    struct CarIconMaker__virtual_10_temp_a1 *temp_a1;
    struct CarIconMaker__virtual_10_temp_s0 *temp_s0;

    temp_a1 = arg0 + 0x44;
    temp_s0 = arg0 + 0x30;
    func_004ACC88(temp_a1->unkC, temp_a1);
    func_004ACC88(temp_s0->unkC, temp_s0);
}
