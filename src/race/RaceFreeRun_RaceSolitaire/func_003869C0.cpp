#include "types.h"

struct Inner {
    char pad[0xE0];
    s32 unkE0;
};

struct Obj {
    char pad[0x6C];
    Inner *unk6C;
};

extern "C" void *func_003869C0(Obj *arg0) {
    Inner *temp_a1 = arg0->unk6C;
    if (temp_a1->unkE0 != 0) {
        return (char *)arg0 + 0xE90C;
    }
    return (char *)arg0 + 0xE54C;
}
