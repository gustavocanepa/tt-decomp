#include "types.h"

struct Obj {
    char pad[0x168];
    u64 flags;
};

extern "C" void func_00553540(Obj *arg0) {
    arg0->flags &= 0xFFFFFFFF00FFFFFFULL;
}
