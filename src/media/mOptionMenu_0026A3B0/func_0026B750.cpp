#include "types.h"

struct Handle {
    s32 obj;
    char pad4[0xC];
};

extern char D_005EF660[]; /* "cursor" */
extern "C" void func_001EEDE8(Handle *h);
extern "C" void func_001EEB30(s32 obj, const char *name);
extern "C" void func_001EDBE0(Handle *h, s32 flags);
extern "C" void func_0026B6E8(void *self, void *arg);

extern "C" void func_0026B750(void *self, void *arg) {
    Handle h;
    func_001EEDE8(&h);
    func_001EEB30(h.obj, D_005EF660);
    func_001EDBE0(&h, 2);
    func_0026B6E8(self, arg);
}
