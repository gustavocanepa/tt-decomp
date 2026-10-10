typedef short s16;
typedef unsigned char u8;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj00393B00 {
    u8 pad0[0xA8];
    VEntry *vtbl;
};

extern "C" void func_0056E2B8(struct Obj00393B00 *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x48);

    e->fn((char *)arg0 + e->delta);
}
