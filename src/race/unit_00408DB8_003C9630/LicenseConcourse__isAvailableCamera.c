#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 LicenseConcourse__isCameraPeriod();                                /* extern */

struct func_003C9FB8_arg0 {
    char pad0[0x78];
    s32 unk78;
};

s32 LicenseConcourse__isAvailableCamera(struct func_003C9FB8_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (LicenseConcourse__isCameraPeriod() != 0) {
        var_v0 = arg0->unk78 != 0;
    }
    return var_v0;
}
