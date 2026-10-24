/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct VEntry { short delta; short pad; void (*fn)(void *, void *); };
struct Target { VEntry *vt; };
struct Self { char pad0[4]; Target *primary; Target *secondary; char padC[4]; int useSecondary; };
struct Short6 { short type; u8 a; u8 b; };
struct Data9 { char d[9]; } __attribute__((packed));
struct Long12 { short type; Data9 data; } __attribute__((packed));
extern "C" void func_004CE488(Self *self, char *src) {
    if (self->useSecondary == 0) {
        Short6 m;
        m.type = 6;
        m.a = src[2];
        m.b = src[3];
        Target *t = self->primary;
        VEntry *e = (VEntry *)((char *)t->vt + 0x18);
        e->fn((char *)t + e->delta, &m);
    } else {
        Long12 m;
        m.type = 12;
        m.data = *(Data9 *)(src + 4);
        Target *t = self->secondary;
        VEntry *e = (VEntry *)((char *)t->vt + 0x18);
        e->fn((char *)t + e->delta, &m);
    }
}
