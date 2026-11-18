#include "types.h"

struct SomeStruct {
    char pad[0x308];
    s32 unk58;
};

extern void func_0013C810(s32);

extern "C" void func_00126938(struct SomeStruct *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk58;
    if (temp_v0 != 0) {
        func_0013C810(temp_v0);
    }
}
