#include "types.h"
#define NULL 0

extern "C" s32 *func_001CE818(s32 arg0);
extern "C" char *func_0050F0F0(void *);

struct func_00126668_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 *func_00126668(s32 *arg0, s32 arg1) {
    s8 *temp_v0;
    s8 *var_a2;
    struct func_00126668_temp_a1 *temp_a1;

    temp_v0 = (s8 *) *func_001CE818(arg1 + 0xB4);
    temp_a1 = (struct func_00126668_temp_a1 *) (temp_v0 - 0x10);
    var_a2 = temp_v0;
    if (temp_a1->unkC != 0) {
        var_a2 = (s8 *) func_0050F0F0(temp_a1);
    } else {
        temp_a1->unk8 = (s32) (temp_a1->unk8 + 1);
    }
    *arg0 = (s32) var_a2;
    return arg0;
}
