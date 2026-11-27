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
    char *text;
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

struct Disp {
    char pad[0x20];
    unsigned int color;
};

struct Self {
    char pad[0x177C];
    Disp disp;
};

extern char D_005F44E8[];
extern "C" void func_00358F18(Event *);
extern "C" int func_003588E0(Event *, Info *, int);
extern "C" void func_0035A5F0(Disp *, char *, s32);
extern "C" void RaceEventDisplay__addEvent(Disp *, char *, float, float, float, float);

extern "C" void func_00355C48(Self *self, Info *info) {
    Event ev;
    func_00358F18(&ev);
    for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
        ev.id = -1;
        if (func_003588E0(&ev, info, i) == 0) return;
        Disp *d = &self->disp;
        func_0035A5F0(d, D_005F44E8, 1);
        d->color = 0x80C8C8C8;
        RaceEventDisplay__addEvent(d, ev.text, 3.0f, 0.0f, 0.0f, 0.0f);
    }
}
