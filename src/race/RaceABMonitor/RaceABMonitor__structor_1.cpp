/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item {
    char pad0[0x14];
    char *vt;
    char pad18[8];
    int f20, f24;
    unsigned int color;
    int f2C;
};
struct Panel {
    char pad0[0x14];
    char *vt;
    int f18, f1C;
    Item items[2];
};
struct VEntry { short delta, index; void (*fn)(void *, int, int); };
extern char D_005D0D78[];
extern "C" int RaceDisplayObjectBase__structor_0(Panel *);
extern "C" void RaceSimpleBarMeter__structor_0(Item *);
extern "C" int RaceABMonitor__structor_1(Panel *p) {
    Item *first = p->items;
    RaceDisplayObjectBase__structor_0(p);
    p->vt = D_005D0D78;
    p->f18 = 0;
    p->f1C = 0;
    Item *item = first;
    RaceSimpleBarMeter__structor_0(first);
    RaceSimpleBarMeter__structor_0(&p->items[1]);
    for (int i = 0; i < 2; i++) {
        VEntry *e = (VEntry *)(item->vt + 0x48);
        e->fn((char *)item + e->delta, 0, 0);
        item->f20 = 0;
        item->f24 = 0;
        item->f2C = 0;
        item++;
    }
    first->color = 0x80E3B896;
    p->items[1].color = 0x800000F0;
}
