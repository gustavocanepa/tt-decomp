#include "types.h"

extern "C" s32 func_0048A4B8(s32 arg0);

struct Obj_001CB668 {
    char pad[8];
    s32 unk8;
};

extern "C" const char *func_001A8990(Obj_001CB668 *arg0) {
    if (func_0048A4B8(arg0->unk8) < 0) {
        return "failed";
    }
    return 0;
}
