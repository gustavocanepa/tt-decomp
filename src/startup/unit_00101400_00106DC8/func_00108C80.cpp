#include "types.h"

struct SomeStruct {
    char pad[0x58];
    s32 unk58;
};

extern void func_004CA568(s32);

extern "C" void func_00108C80(struct SomeStruct *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk58;
    if (temp_v0 != 0) {
        func_004CA568(temp_v0);
    }
}
