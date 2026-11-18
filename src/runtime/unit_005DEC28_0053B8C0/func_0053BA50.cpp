#include "types.h"
struct Blob { char d[0xAE]; } __attribute__((packed, aligned(2)));
struct VEntry { s16 delta; s16 pad; int (*fn)(void *); };
struct Source { VEntry *vtable; };
struct Self { char pad[0x10]; Source *source; Blob blob; };
struct Dest { char pad[0x10]; int tag; Blob blob; };
extern "C" void func_0053BA50(Self *self, Dest *dest) {
    Source *s = self->source;
    VEntry *e = (VEntry *)((char *)s->vtable + 0x20);
    dest->tag = e->fn((char *)s + e->delta);
    dest->blob = self->blob;
}
