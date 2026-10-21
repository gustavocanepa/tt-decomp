/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef short s16;

struct Blob { s32 w[9]; };

struct Half { u16 pad; u16 h2; };

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Target {
    char *vtbl;
};

struct Self {
    char pad0[0x14];
    Half h14;
    char pad18[0xC8 - 0x18];
    Half *pC8;
    s32 unkCC;
    char padD0[0x170 - 0xD0];
    Blob s170;
    char pad194[0x194 - 0x194];
    Target *p194;
    s32 w198;
    s32 w19C;
    Blob s1A0;
    s32 unk1C4;
    char pad1C8[0x1D4 - 0x1C8];
    s32 unk1D4;
};

extern "C" void func_003EB550(void *);
extern "C" void MenuControl__virtual_01(void *);

typedef s32 (*Fn1)(void *, Blob *, Half *, s32);
typedef s32 (*Fn2)(void *);

extern "C" void RaceInput__fetch(Self *self) {
    s32 mode;
    Half *h = &self->h14;
    MenuControl__virtual_01(self);
    u16 a = h->h2;
    u16 b = self->pC8->h2;
    self->w198 = b;
    if (a != self->w19C) {
        self->w19C = a;
        self->w198 = b & 0xFFFC;
    }
    if (self->p194 != 0) {
        mode = 1;
        switch (self->unk1C4) {
        case 0:
            mode = 0;
            if (self->unk1D4 != 0) {
                mode = 2;
            }
            break;
        case 1:
            mode = 3;
            break;
        }
        self->s1A0 = self->s170;
        {
            Target *t = self->p194;
            VEntry *e = (VEntry *)(t->vtbl + 0x30);
            ((Fn1)e->fn)((char *)t + e->delta, &self->s170, h, mode);
        }
        {
            Target *t = self->p194;
            VEntry *e = (VEntry *)(t->vtbl + 0x40);
            self->unkCC = ((Fn2)e->fn)((char *)t + e->delta);
        }
        func_003EB550(self);
    }
}
