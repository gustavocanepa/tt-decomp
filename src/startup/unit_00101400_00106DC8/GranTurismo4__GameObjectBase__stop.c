/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68();                            /* extern */
s32 func_004A4DD8(void *);                      /* extern */

struct CarIconMaker__virtual_02_arg0 {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
};

void GranTurismo4__GameObjectBase__stop(struct CarIconMaker__virtual_02_arg0 *arg0) {
    func_004A4D68();
    if (arg0->unk5C != 0) {
        arg0->unk60 = 1;
    }
    func_004A4DD8(arg0);
}
