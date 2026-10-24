#include "types.h"

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct Self { char pad[0x60]; s32 m60; VEntry *vtbl; };
extern "C" void func_001009F8(Self *);

extern "C" void func_001095B8(Self *self) {
    func_001009F8(self);
    if (self->m60 != 0) {
        VEntry *e = &self->vtbl[9];
        e->fn((char *)self + e->delta);
    }
}
