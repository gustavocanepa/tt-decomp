#include "types.h"

struct Obj {
    char pad[0x10];
    void *unk10;
};

extern "C" int func_003FD830(void *a0, void *a1);

extern "C" void func_0051B690(struct Obj *arg0) {
    func_003FD830(arg0->unk10, (void *)1);
}
