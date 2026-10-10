#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CA090();                            /* extern */

extern char D_005D73C8[];
struct PhotoModeInput__structor_0_arg0 {
    char pad0[0xD0];
    s32 unkD0;
    char padD4[0x4];
    s32 unkD8;
};

void PhotoModeInput__structor_0(struct PhotoModeInput__structor_0_arg0 *arg0) {
    func_004CA090();
    arg0->unkD8 = 0;
    arg0->unkD0 = (s32)D_005D73C8;
}
