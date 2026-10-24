#include "types.h"

struct Obj {
    char pad[0x1C];
    void *p;
};

extern char D_005F5910[];
extern "C" void *func_00357310(void *);

extern "C" void RaceMTRMeterPanel__init_texset(Obj *self) {
    if (self->p == 0)
        self->p = func_00357310(D_005F5910);
}
