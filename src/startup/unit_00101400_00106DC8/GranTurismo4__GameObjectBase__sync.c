/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectBase__stop();                            /* extern */
s32 func_004A4D68(void *);                      /* extern */
s32 func_004A4DD8(void *);                      /* extern */
s32 func_004A4E08(void *);                      /* extern */

struct CarIconMaker__virtual_03_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

void GranTurismo4__GameObjectBase__sync(struct CarIconMaker__virtual_03_arg0 *arg0) {
    GranTurismo4__GameObjectBase__stop();
    func_004A4D68(arg0);
    if (arg0->unk5C != 0) {
        func_004A4E08(arg0);
    }
    func_004A4DD8(arg0);
}
