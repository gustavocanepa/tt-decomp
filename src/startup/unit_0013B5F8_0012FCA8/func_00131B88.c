#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00131AF8(s32);                             /* extern */
s32 func_00408B58(s32);                             /* extern */
s32 SPEC_DATABASE__CarEquipments__getDriveTrainType(s32);                             /* extern */
s32 func_0040DA58(s32);                             /* extern */

extern char D_005E0FA8[];
struct func_00131B88_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00131B88(struct func_00131B88_arg0 *arg0) {
    if (func_0040DA58(func_00408B58(arg0->unk14)) == 0) {
        return (s32)D_005E0FA8;
    }
    return func_00131AF8(SPEC_DATABASE__CarEquipments__getDriveTrainType(func_00408B58(arg0->unk14)));
}
