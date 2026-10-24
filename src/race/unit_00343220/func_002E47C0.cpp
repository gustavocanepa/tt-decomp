#include "types.h"

struct Self { char pad[4]; f32 m4; char pad2[0xC]; u8 m14; };
extern char D_00582E98[];
extern "C" f32 func_002F4F68(char *);

extern "C" void func_002E47C0(Self *self) {
    if (self->m14 == 0) {
        self->m4 = func_002F4F68(D_00582E98);
    }
}
