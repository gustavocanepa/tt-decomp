#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00108B40();                            /* extern */

struct CarIconMaker__virtual_12_arg0 {
    char pad0[0x68];
    s32 unk68;
};

s32 GranTurismo4__GameObjectPS2__internal_render(struct CarIconMaker__virtual_12_arg0 *arg0) {
    if (arg0->unk68 < 2) {
        func_00108B40();
    }
}
