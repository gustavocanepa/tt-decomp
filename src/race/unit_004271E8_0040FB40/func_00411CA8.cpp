#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0047DB20(void *buf, s32 arg1, s32 arg2);
extern "C" s32 func_00411D58(struct Obj *obj);

extern "C" s32 func_00411CA8(struct Obj *arg0, s32 arg1) {
    char buf[0x20] __attribute__((aligned(8)));

    func_0047DB20(buf, arg1, 1);
    arg0->unk0 = *(s32 *) (buf + 0x10);
    arg0->unk4 = *(s32 *) (buf + 0x8);
    if (func_00411D58(arg0) == 0) {
        return -1;
    }
    return arg0->unk4;
}
