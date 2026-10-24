#include "types.h"

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void RaceCourse__clearData(s32 arg0);
extern char D_00584038;

extern "C" void *func_00375A68(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk80;

    if (temp_v0 != 0) {
        RaceCourse__clearData(temp_v0);
    }
    return &D_00584038;
}
