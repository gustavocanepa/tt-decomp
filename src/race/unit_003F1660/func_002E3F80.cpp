/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Inner { char p[0x6C]; u8 b6c, b6d, b6e, b6f; float f70, f74; };
struct Car { char p0[0x14]; Inner s; char p1[0x58A - 0x14 - sizeof(Inner)]; u8 b56a; };
struct Entry { short adj; char pad[2]; int (*fn)(void *); };
struct Self { char p[0x241CC]; char *tbl; };
extern u8 D_00582CA8, D_00582CA9;
extern float D_00582CF0[], D_00582CD8[];
extern u8 D_00582CD0[];
extern "C" Car *func_002F04D8(Self *);
extern "C" int func_002F8A68(Car *);

static inline void setup(Inner *s, const u8 &v, int enabled) {
    s->b6d=v;
    s->f74=D_00582CF0[v];
    s->f70=D_00582CD8[v];
    s->b6f=D_00582CD0[v];
    s->b6e=enabled;
}
extern "C" void func_002E3F80(Self *self)
{
    Car *c = func_002F04D8(self);
    Inner *s = &c->s;
    if (c->b56a < 2) setup(s,D_00582CA8,0);
    else setup(s,D_00582CA9,1);
    Entry *e = (Entry *)(self->tbl + 0x30);
    if (e->fn((char *)self + e->adj) != 0)
        s->b6e = 0;
    if (func_002F8A68(c) == 0)
        s->b6f = -0x80;
    s->b6c = 0;
}
