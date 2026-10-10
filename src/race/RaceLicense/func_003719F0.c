#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D5E88(s32, void *);
s32 LicenseConcourse__isCameraPeriod(s32);
struct func_003719F0_arg1 {
    char pad0[0x18];
    void *unk18;
};
struct func_003719F0_temp_s2 {
    char pad0[0x565];
    u8 unk565;
};

s32 func_003719F0(s32 arg0, struct func_003719F0_arg1 *arg1) {
    struct func_003719F0_temp_s2 *temp_s2;
    temp_s2 = arg1->unk18;
    if ((LicenseConcourse__isCameraPeriod(arg0 + 0x3A8C0) != 0) && (temp_s2->unk565 != 0)) {
        return 0;
    }
    return func_002D5E88(arg0, arg1);
}
