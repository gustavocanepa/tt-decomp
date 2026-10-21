/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
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
    int pad;
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

struct Car { char pad[0x5D3]; signed char flag; };
struct Item { char pad[0x18]; Car *car; };
struct List { char pad[8]; Item **items; };
struct Info2 { char pad[0x60]; List *list; };

struct Self {
    char pad0[4];
    Info2 *info;
    char pad8[0xCC - 8];
    f32 bc;
};

extern VEntry D_005CFB50[];
extern "C" void *func_00358B80(Event *);
extern "C" int func_003588E0(Event *, Info *, int);
extern "C" int func_003542A0(Self *, int) throw();
extern "C" void func_00356188(Self *, int, int);

extern "C" void func_003556D0(Self *self, Info *info, int arg2) {
    if (!(self->bc < 1.0f)) {
        Event ev;
        func_00358B80(&ev);
        ev.vtbl = D_005CFB50;
        if (info->sub.count(vcall1(ev.vtbl, &ev)) != 0) {
            int mode = self->info->list->items[arg2]->car->flag;
            if (mode == 1) {
                int key = func_003542A0(self, 2);
                for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
                    ev.id = key;
                    if (func_003588E0(&ev, info, i) != 0) {
                        func_00356188(self, -ev.value, key);
                    }
                }
            } else {
                for (int i = 0; i < info->sub.count(vcall1(ev.vtbl, &ev)); i++) {
                    ev.id = arg2;
                    if (func_003588E0(&ev, info, i) != 0) {
                        int v = ev.value;
                        func_00356188(self, v, func_003542A0(self, 1));
                    }
                }
            }
        }
    }
}
