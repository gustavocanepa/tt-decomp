typedef short s16;
typedef int s32;

struct VEntryV {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct VEntryP {
    s16 delta;
    s16 index;
    void *(*fn)(void *self, s32 a1);
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad1[0xE0C - 0x68];
    s32 m_d48;
};

extern "C" void func_0031AAC0(void *arg0, s32 arg1);

extern "C" void func_0033AE38(Obj *self) {
    VEntryV *e1 = (VEntryV *)(self->vtbl + 0x178);
    e1->fn((char *)self + e1->delta);
    if (self->m_d48 != 0) {
        VEntryP *e2 = (VEntryP *)(self->vtbl + 0xD0);
        void *r = e2->fn((char *)self + e2->delta, 0);
        func_0031AAC0(r, 0);
    }
}
