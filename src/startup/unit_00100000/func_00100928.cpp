#include "types.h"

extern char D_00578E28[];
extern char D_00578E68[];
extern char D_005A48F8[];
struct Self { char pad[0x64]; char *vtbl; s32 m68; };
extern "C" void *func_00108888(Self *, char *, char *);

extern "C" void *func_00100928(Self *self) {
    void *r = func_00108888(self, D_00578E28, D_00578E68);
    self->m68 = 0;
    self->vtbl = D_005A48F8;
    return r;
}
