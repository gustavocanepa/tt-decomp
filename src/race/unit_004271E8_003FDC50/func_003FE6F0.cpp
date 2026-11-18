#include "types.h"

struct Struct_00437E98 {
    char pad[6];
    s8 unk6;
};

extern "C" void func_003FE710(struct Struct_00437E98 *arg0);

extern "C" void func_003FE6F0(struct Struct_00437E98 *arg0, s8 arg1) {
    arg0->unk6 = arg1;
    func_003FE710(arg0);
}
