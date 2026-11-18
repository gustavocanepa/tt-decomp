#include "types.h"

struct SomeStruct {
    char pad[0x1C];
    s32 unk1C;
};

extern void func_00466F18(s32);

void func_00418F70(struct SomeStruct *arg0) {
    s32 temp_v0;

    if (arg0 != 0) {
        temp_v0 = arg0->unk1C;
        if (temp_v0 != 0) {
            func_00466F18(temp_v0);
        }
    }
}
