#include "types.h"

struct Self {
    char pad[0x5910];
    s32 m4384;
};

struct Src {
    char pad[0x88];
    s32 m88;
};

extern "C" void AutomaticFader__fadeout(void *self, f32 t);

extern "C" void func_003720A0(struct Self *self, struct Src *arg1) {
    s32 t;

    if (self->m4384 <= 0) {
        t = arg1->m88;
        if (t > 0) {
            self->m4384 = t;
            AutomaticFader__fadeout((char *)self + 0xCC, 0x1.0p-2f);
        }
    }
}
