#include "types.h"

struct Obj {
    char pad[0x10];
    void *unk10;
};

extern "C" int func_003FD7E8(void *a0, void *a1);

extern "C" void func_0051B520(struct Obj *arg0) {
    func_003FD7E8(arg0->unk10, 0);
}
