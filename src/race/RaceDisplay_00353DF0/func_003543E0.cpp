/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

static inline int vcall1(VEntry *vtbl, void *o) {
    VEntry *e = &vtbl[1];
    return e->fn((char *)o + e->delta);
}

struct Event {
    int id;
    VEntry *vtbl;
    int value;
    int kind;
};

struct Sub {
    char pad[0x800];
    u8 counts[1];
    int count(int t) { return counts[t]; }
};

struct Info {
    char pad0[0xFC];
    Sub sub;
};

struct VEntryV { s16 delta; s16 index; void (*fn)(void *, s32, s32); };

struct Self {
    char *vtbl;
    char pad4[0x2F - 4];
    signed char id2F;
};

extern VEntry D_005CFB28[];
extern "C" void func_00358988(Event *);
extern "C" Event *func_00358B80(Event *);
extern "C" int func_003588E0(Event *, Info *, int);
extern "C" s32 func_00358D18(Event *);
extern "C" void func_00354528(Self *, Info *, s32);

extern "C" void func_003543E0(Self *self, Info *info, s32 key) {
    Event ev;
    func_00358988(&ev);
    for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
        if (func_003588E0(&ev, info, i) == 0) continue;
        s32 id = ev.id;
        s32 val = ev.value;
        Event ev2;
        Event *p = &ev2;
        func_00358B80(p);
        ev2.vtbl = D_005CFB28;
        p->id = id;
        if (func_003588E0(p, info, 0) == 0) continue;
        s32 r = func_00358D18(p);
        if (id == self->id2F) func_00354528(self, info, r);
        if (id == key) {
            VEntryV *e = (VEntryV *)(self->vtbl + 0x1A0);
            e->fn((char *)self + e->delta, val, r);
        }
    }
}
