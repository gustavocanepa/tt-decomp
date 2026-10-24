#include "types.h"

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_00484078(Obj *arg0);

extern "C" void func_00484050(Obj *arg0) {
    s32 result = func_00484078(arg0);
    arg0->unk10 = result;
}
