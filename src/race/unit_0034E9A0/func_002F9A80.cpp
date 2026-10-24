#include "types.h"

extern f32 D_0076739C;

struct Obj00355D88 {
    char pad[0x7E4];
    f32 unk788;
};

extern "C" f32 func_002F9A80(struct Obj00355D88 *arg0) {
    return arg0->unk788 / D_0076739C;
}
