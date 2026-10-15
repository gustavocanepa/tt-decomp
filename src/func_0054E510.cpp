typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Holder {
    char pad[8];
    void **top;
};

struct Self {
    char pad[0x10];
    Holder h;
};

extern "C" void func_0054E510(Self *self) {
    Holder *h = &self->h;
    void **s0 = (void **)h->top[-1];

    VEntry *e = (VEntry *)((char *)*s0 + 0x18);
    e->fn((char *)s0 + e->delta, (s32)self);

    VEntry *e2 = (VEntry *)((char *)*s0 + 0x8);
    e2->fn((char *)s0 + e2->delta, 3);

    h->top = (void **)((char *)h->top - 4);
}
