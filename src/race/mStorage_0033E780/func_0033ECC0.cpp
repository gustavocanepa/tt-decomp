/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct VObj;
struct VEntry { s16 delta; s16 pad; void (*fn)(void *); };
struct VEntryR { s16 delta; s16 pad; VObj *(*fn)(void *); };
struct VObj { VEntry *vtbl; };
struct VObj2 { char *vtbl; };

struct Self {
    char pad0[0x64];
    char *tbl;
    char pad68[0xD8C - 0x68];
    u32 mode;
};

extern "C" void func_0033CE68(void *, void *);
extern "C" void RaceInput__setRunMode(void *, void *);
extern "C" void func_0033DF60(void *, void *);
extern "C" void func_0033E078(void *, void *);
extern "C" void func_002CF610(void *);
extern "C" void func_0034E948(void *);

extern "C" void func_0033ECC0(Self *self, void *arg1) {
    char *p = (char *)self + 0x32710;
    int i = 1;
    func_0033CE68(self, arg1);
    do {
        char *q = p;
        p += 0x1E0;
        i--;
        RaceInput__setRunMode(q, arg1);
    } while (i >= 0);
    if (self->mode - 2 < 2) {
        func_0033DF60(self, (char *)self + 0x3330C);
        func_0033E078(self, 0);
    } else {
        func_0033DF60(self, (char *)self + 0x3330C);
        func_0033E078(self, (char *)self + 0x32B00);
    }
    func_002CF610(self);
    VEntryR *e = (VEntryR *)(self->tbl + 0x500);
    VObj *o = e->fn((char *)self + e->delta);
    VEntry *e2 = (VEntry *)((char *)o->vtbl + 0x48);
    e2->fn((char *)o + e2->delta);
    func_0034E948((char *)self + 0xE220);
}
