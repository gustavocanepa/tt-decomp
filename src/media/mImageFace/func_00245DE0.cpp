#include "types.h"

struct Struct_002A39F0 {
    char pad[0x176];
    s8 unkEC;
    s8 unkED;
};

extern "C" void func_00245C50(Struct_002A39F0 *arg0);

extern "C" void func_00245DE0(Struct_002A39F0 *arg0, s8 arg1, s8 arg2) {
    arg0->unkEC = arg1;
    arg0->unkED = arg2;
    func_00245C50(arg0);
}
