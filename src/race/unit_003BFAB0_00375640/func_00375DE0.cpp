/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef short s16;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct Ev { s32 idx; char *vt; s32 f8; s32 fC; };
struct Car { char pad[0x12B0]; s32 f11E8; s32 f11EC; };
struct Arr { char pad[8]; Car **cars; };
struct Self {
    char pad0[0xC0];
    s32 fC0;
    char padC4[0xE8 - 0xC4];
    s32 fE8;
    char padEC[0xF4 - 0xEC];
    char qF4[8];
    char bytes[0x800 + 0x100];
};
struct SelfW { char pad[0x60]; Arr *f60; };

extern char D_005CFB78[];
extern char D_005CFB50[];

extern "C" void *func_00358B80(Ev *);
extern "C" s32 func_003588E0(Ev *, void *, s32);
extern "C" s32 func_00358CB8(Ev *);
extern "C" void func_0036C1E8(void *);
extern "C" s32 RaceEventQueue__get(void *, s32, void *, s32);

struct Events { char pad[0x800]; u8 counts[256]; };
static inline s32 count(Ev *pe, Ev *ev, Events *base) {
    VEntry *e = (VEntry *)(ev->vt + 8);
    return base->counts[e->fn((char *)pe + e->delta)];
}

static inline int getEvent(Ev *ev, char *self, int key) { ev->idx = -1; return func_003588E0(ev,self,key); }

static inline void setTime(Car *c, int t) { c->f11E8=t; c->f11EC=0; }

extern "C" void func_00375DE0(char *self) {
    s32 sp0;
    char *q = self + 0xF4;
    func_0036C1E8(((SelfW *)self)->f60);
    if (RaceEventQueue__get(q, 8, 0, 1) != 0) {
        *(s32 *)(self + 0xC0) = 0;
    }
    *(s32 *)(self + 0xE8) = 0;
    while (RaceEventQueue__get(q, 0xF, &sp0, 1) != 0) {
        if (sp0 == 0) *(s32 *)(self + 0xE8) = 1;
    }
    {
    Ev ev;
    Ev *pe = &ev;
    s32 j = 0;
    func_00358B80(pe);
    ev.vt = D_005CFB78;
    for (;j < count(pe, &ev, (Events *)(self + 0xFC));j++) {
        if (getEvent(pe, self, j) != 0) {
            Car *c = ((SelfW *)self)->f60->cars[pe->idx];
            if (c != 0) {
                setTime(c,func_00358CB8(pe));
            }
        }
    }
    }
    {
    Ev ev;
    Ev *pe = &ev;
    func_00358B80(pe);
    int k = 0;
    ev.vt = D_005CFB50;
    for (;k < count(pe, &ev, (Events *)(self + 0xFC));k++) {
        if (getEvent(pe, self, k) != 0) {
            Car *c = ((SelfW *)self)->f60->cars[pe->idx];
            if (c != 0) {
                c->f11E8 = 0x157529FF;
                c->f11EC = ev.f8;
            }
        }
    }
}
}
