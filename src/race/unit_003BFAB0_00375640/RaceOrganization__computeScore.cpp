#include "types.h"

struct Car {
    char pad[0x5D0];
    char pad5B0[3];
    signed char m5B3;
    int State() const { return m5B3; }
};

struct Holder {
    char pad[0x18];
    Car *car;
};

struct List {
    s32 kind;
    s32 pad;
    Holder **items;
};

struct Self {
    char pad[0x60];
    List *list;
    char pad2[0x96C - 0x64];
    signed char m96C;
};

extern "C" f32 func_003035F8(Car *, s32);
extern "C" signed char func_00376CD0(Self *, s32);

extern "C" void RaceOrganization__computeScore(Self *self, s32 i) {
    List *list = self->list;
    if (list->kind != 1) {
        Car *c = list->items[i]->car;
        if (((unsigned)c->State() < 2) && !(func_003035F8(c, 1) > 0.0f)) {
            self->m96C = func_00376CD0(self, i);
        }
    }
}
