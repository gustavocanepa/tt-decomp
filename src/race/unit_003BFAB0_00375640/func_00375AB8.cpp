#include "types.h"

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_0034A600(void);
extern "C" void RaceCourse__clearData(s32 arg0);

extern "C" void func_00375AB8(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk80;

    if (temp_v0 != 0) {
        RaceCourse__clearData(temp_v0);
    }
    func_0034A600();
}
