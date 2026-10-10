/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00253EB8();                                /* extern */
f32 func_00254000();                                /* extern */

struct func_00254268_arg0 {
    char pad0[0x11C];
    f32 unk11C;
    char pad120[0x24];
    s32 unk144;
};

f32 func_00254268(struct func_00254268_arg0 *arg0) {
    if (arg0->unk144 != 0) {
        return func_00254000();
    }
    return func_00253EB8() * arg0->unk11C;
}
