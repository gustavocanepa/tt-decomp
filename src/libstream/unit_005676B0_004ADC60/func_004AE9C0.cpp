#include "types.h"

struct S00574D78 {
    char pad[0x28];
    s32 unk28;
    s32 unk2C;
};

extern "C" void func_004A4998();

extern "C" void func_004AE9C0(S00574D78 *arg0) {
    func_004A4998();
    arg0->unk28 = 0;
    arg0->unk2C = 0;
}
