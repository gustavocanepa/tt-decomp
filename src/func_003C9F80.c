#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003C9F80_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x8];
    s32 unk24;
    char pad28[0x14];
    s32 unk3C;
};

s32 LicenseConcourse__isCameraPeriod(struct func_003C9F80_arg0 *arg0) {
    if (arg0->unk18 != 0) {
        if (arg0->unk3C != 0) {
            if (arg0->unk24 >= 2) {
                return 1;
            }
        }
    }
    return 0;
}
