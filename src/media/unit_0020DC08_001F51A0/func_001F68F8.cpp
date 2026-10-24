#include "types.h"

extern char D_005EAB18[];
extern "C" s32 func_004B4C18(void *);
extern "C" void func_001C1098(void *, const char *, s32);

extern "C" void func_001F68F8(void *self) {
    const char *name = D_005EAB18;
    func_001C1098(self, name, func_004B4C18(self));
}
