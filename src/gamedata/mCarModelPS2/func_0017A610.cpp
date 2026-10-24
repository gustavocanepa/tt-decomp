#include "types.h"

struct Struct_00156700 {
    char pad[0x180];
    s32 unk174;
};

extern "C" void func_0017A638(void);

extern "C" void func_0017A610(struct Struct_00156700 *arg0)
{
    if (arg0->unk174 == 0) {
        return;
    }
    func_0017A638();
}
