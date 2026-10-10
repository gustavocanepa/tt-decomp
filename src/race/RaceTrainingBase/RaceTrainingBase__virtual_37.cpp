struct VEntry { short delta; short index; void (*fn)(void *, int); };
struct VObj { VEntry *vtbl; };
struct X { char pad[0xDC]; int busy; };
struct Y { char pad[0x34]; int f34; int f38; };
struct Big {
    char pad0[0x6C];
    X *x6c;
    char pad1[0xD8C - 0x70];
    int mode;
    char pad2[0xE41C - 0xCCC];
    VObj *obj;
    char pad3[0x13B40 - 0xE424];
    Y y;
};
extern void func_0037ACC8(Big *);
extern void func_0033DF60(Big *, Y *);
extern void func_0033E078(Big *, int);
void RaceTrainingBase__virtual_37(Big *b)
{
    func_0037ACC8(b);
    int m = b->mode;
    if (m == 2 || m == 3) {
        func_0033DF60(b, &b->y);
        func_0033E078(b, 0);
    } else {
        Y *y = &b->y;
        y->f34 = (m == 1 || m == 3);
        func_0033DF60(b, &b->y);
    }
    VObj *o = b->obj;
    if (o) {
        int flag = 0;
        if (b->x6c->busy == 0)
            flag = b->y.f38 != 0;
        VEntry *e = &o->vtbl[17];
        e->fn((char *)o + e->delta, flag);
    }
}
