#include "types.h"

struct Self { char *vtbl; char m4[0xB8]; char mBC[4]; };
extern char D_005D94A0[];
extern "C" void *func_003FF3F0(Self *);
extern "C" void func_00402A40(void *);

extern "C" void func_00403468(Self *self) {
    func_003FF3F0(self);
    self->vtbl = D_005D94A0;
    func_00402A40(self->m4);
    func_00402A40(self->mBC);
}
