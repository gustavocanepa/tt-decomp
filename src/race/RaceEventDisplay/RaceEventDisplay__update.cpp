typedef float f32;

struct VEnt_003A4FC8 {
    short delta;
    short index;
    void (*fn)(void *self, f32 t);
};

struct Item_003A4FC8 {
    char pad0[0x14];
    char *vt;
    char pad18[0x150 - 0x18];
};

struct RaceEventDisplay_003A4FC8 {
    char pad0[0x24];
    f32 f24;
    f32 f28;
    char pad30[0x50 - 0x2C];
    Item_003A4FC8 items[8];
};

static inline f32 fmax_s_003A4FC8(f32 a, f32 b) {
    f32 r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" void RaceEventDisplay__update(RaceEventDisplay_003A4FC8 *self, f32 t) {
    Item_003A4FC8 *it = self->items;
    int n = 7;
    do {
        n--;
        VEnt_003A4FC8 *e = (VEnt_003A4FC8 *)(it->vt + 0x50);
        e->fn((char *)it + e->delta, t);
        it++;
    } while (n >= 0);

    f32 a = self->f24;
    f32 b = self->f28;
    f32 zero = 0.0f;
    self->f24 = fmax_s_003A4FC8(a - t, zero);
    self->f28 = fmax_s_003A4FC8(b - t, zero);
}
