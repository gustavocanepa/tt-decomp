#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

u16 func_002E4520(void *, s32);
struct func_00314640_arg0_unk10 {
    char pad0[0x26E];
    u16 unk26E;
};
struct func_00314640_arg0 {
    char pad0[0x10];
    struct func_00314640_arg0_unk10 *unk10;
    char pad14[0x574];
    s32 unk588;
};

u16 func_00314640(struct func_00314640_arg0 *arg0) {
    u16 var_a1;
    var_a1 = arg0->unk10->unk26E;
    if ((arg0->unk588 & 0xFFFF0000) == 0x10000) {
        var_a1 = func_002E4520(arg0, (s32) var_a1);
    }
    return var_a1;
}
