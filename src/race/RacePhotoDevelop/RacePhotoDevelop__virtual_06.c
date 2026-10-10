/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectPS2__terminate(void *);                      /* extern */
s32 func_002C8B08();                            /* extern */

struct RacePhotoDevelop__virtual_06_arg0 {
    char pad0[0x447AC];
    s32 unk447AC;
    s32 unk447B0;
};

void RacePhotoDevelop__virtual_06(struct RacePhotoDevelop__virtual_06_arg0 *arg0) {
    if ((arg0->unk447AC < 0) && (arg0->unk447B0 == 0)) {
        func_002C8B08();
        GranTurismo4__GameObjectPS2__terminate(arg0);
    }
}
