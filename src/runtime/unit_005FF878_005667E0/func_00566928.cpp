#include "types.h"

struct UnkStruct {
    char pad[0xC];
    s32 unkC;
};

extern "C" s32 func_00566928(UnkStruct **arg0) {
    return (*arg0)->unkC;
}
