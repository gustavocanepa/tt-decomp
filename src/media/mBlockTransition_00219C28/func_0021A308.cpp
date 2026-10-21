#include "types.h"

struct Obj0027AEB0 {
    char pad[0x38];
    s32 unk38;
};

extern "C" void func_004A45D0(s32 arg0);

extern "C" void func_0021A308(struct Obj0027AEB0 *arg0) {
    s32 temp_v0 = arg0->unk38;

    if (temp_v0 != 0) {
        arg0->unk38 = 0;
        func_004A45D0(temp_v0);
    }
}
