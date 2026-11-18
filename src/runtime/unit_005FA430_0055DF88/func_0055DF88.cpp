#include "types.h"

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct Self { u8 active; char pad[0x13]; VEntry *vtbl; };

extern "C" void func_0055DF88(Self *self) {
    if (self->active) {
        VEntry *e = &self->vtbl[5];
        e->fn((char *)self + e->delta);
    }
}
