#include "types.h"

struct Obj004336D0 {
    char pad0[0x230];
    u8 unk230;
};

extern "C" s32 func_003FA2A0(struct Obj004336D0 *arg0, s32 arg1) {
    struct Obj004336D0 *p = arg0;
    if (arg1 >= 0xFF) {
        arg1 = 0xFF;
    }
    if ((u32)p->unk230 < (u32)(u8)arg1) {
        p->unk230 = (u8)arg1;
        return 1;
    }
    return 0;
}
