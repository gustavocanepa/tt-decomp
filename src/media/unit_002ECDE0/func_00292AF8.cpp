#include "types.h"

struct Sym {
    s32 id;
    s32 pad[3];
};

extern char D_00582A08[];

extern "C" s32 func_002BF120(const char *name);
extern "C" void func_002C11E8(void *self, Sym *sym);

extern "C" void func_00292AF8(void *self) {
    Sym s;
    s.id = func_002BF120(D_00582A08);
    func_002C11E8(self, &s);
}
