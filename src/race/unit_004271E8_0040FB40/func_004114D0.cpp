#include "types.h"

struct Entry {
    u8 value;
    u8 valid;
};

struct Obj {
    char pad[0x10];
    Entry *table;
    Entry *get(u8 id) { return &table[id]; }
};

extern "C" s32 func_00411518(Obj *, s32, u8 *);

extern "C" u8 func_004114D0(Obj *self, s32 id, u8 *out) {
    Entry *e = self->get(id);
    u8 r = e->valid;
    u8 val = e->value;
    if (r == 0)
        r = func_00411518(self, id, out);
    else
        *out = val;
    return r;
}
