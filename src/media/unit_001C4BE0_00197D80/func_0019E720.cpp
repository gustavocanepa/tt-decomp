#include "types.h"

struct Obj {
    char pad0[0x48];
    u16 flags;
    char pad4A[0x2E];
    char name[0x40];
};

extern "C" char *func_004F8588(char *dst, const char *src, s32 n);

extern "C" s32 func_0019E720(Obj *self, const char *name) {
    char *d = self->name;
    if ((u16)(self->flags & 1) == 0) {
        return 0;
    }
    d[0x3F] = 0;
    func_004F8588(d, name, 0x3F);
    return 1;
}
