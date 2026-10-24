#include "types.h"

struct Obj {
    char pad[0x9C];
    s32 unk9C;
};

extern Obj *D_00579318;

extern "C" s32 func_00109960(void) {
    Obj *p = D_00579318;
    if (p == 0) {
        return 0;
    }
    return p->unk9C;
}
