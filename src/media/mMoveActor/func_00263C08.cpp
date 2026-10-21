#include "types.h"

struct Obj {
    char pad[0x70];
    float unk70;
};

extern "C" void func_00263B98(Obj *arg0, void *arg1, float arg2);

extern "C" void func_00263C08(Obj *arg0) {
    func_00263B98(arg0, (char *)arg0 + 0x60, arg0->unk70);
}
