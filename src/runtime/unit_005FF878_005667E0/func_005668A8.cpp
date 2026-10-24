#include "types.h"

struct UnkStruct2 {
    char pad[0x4];
    s32 unk4;
};

extern "C" s32 func_005668A8(UnkStruct2 **arg0) {
    return (*arg0)->unk4;
}
