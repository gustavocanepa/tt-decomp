#include "types.h"

struct Obj001D0338 {
    char pad0[0x18C];
    s32 unk14C;
};

extern char D_00579F30[];
extern char D_00579F38[];

extern "C" s32 func_001A0D20(struct Obj001D0338 *arg0) {
    if (arg0->unk14C != 0) {
        return (s32)D_00579F30;
    }
    return (s32)D_00579F38;
}
