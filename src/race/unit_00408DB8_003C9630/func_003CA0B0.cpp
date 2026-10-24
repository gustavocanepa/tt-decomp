#include "types.h"

struct Obj00409828 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x8];
    s32 unk24;
    s32 unk28;
};

extern "C" s32 func_003CA0B0(struct Obj00409828 *arg0) {
    s32 temp_a1;

    if (arg0->unk18 != 0) {
        temp_a1 = arg0->unk24;
        if (temp_a1 == 2) {
            if (arg0->unk28 != temp_a1) {
                return 1;
            }
        }
    }
    return 0;
}
