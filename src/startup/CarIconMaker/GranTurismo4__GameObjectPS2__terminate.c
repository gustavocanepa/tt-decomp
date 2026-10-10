/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68();                            /* extern */
s32 func_004A4DD8(void *);                      /* extern */

struct CarIconMaker__virtual_08_arg0 {
    char pad0[0x68];
    s32 unk68;
};

void GranTurismo4__GameObjectPS2__terminate(struct CarIconMaker__virtual_08_arg0 *arg0) {
    func_004A4D68();
    if (arg0->unk68 == 0) {
        arg0->unk68 = 1;
    }
    func_004A4DD8(arg0);
}
