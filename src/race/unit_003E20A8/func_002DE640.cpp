#include "types.h"

struct Obj {
    char pad[0x44];
    u8 unk44;
};

extern "C" void *D_0061B704;

extern "C" f32 func_002DE640(Obj *arg0) {
    char *p = (char *)D_0061B704 + (s32)arg0->unk44 * 0xA0;
    return *(f32 *)(p + 0xB4);
}
