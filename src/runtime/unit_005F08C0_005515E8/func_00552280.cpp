#include "types.h"

struct Obj {
    char pad[0xE10];
    s32 unkE10;
};

extern "C" char *func_00552280(struct Obj *arg0) {
    return (char *)arg0 + ((1 - arg0->unkE10) * 0x700) + 0x10;
}
