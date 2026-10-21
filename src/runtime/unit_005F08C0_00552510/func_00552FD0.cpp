#include "types.h"

struct Obj {
    char pad[0x168];
    u64 flags;
};

extern "C" void func_00552FD0(Obj *arg0, int arg1) {
    arg0->flags = (arg0->flags & 0xFFFFFFFF00FFFFFFULL) | ((u64)(arg1 & 0xFF) << 24);
}
