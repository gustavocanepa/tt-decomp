struct VEntry {
    short delta;
    short index;
    unsigned int (*fn)(void *);
};

struct Saver {
    VEntry *vt;
};

extern Saver *D_005857DC;
extern "C" unsigned int func_0019D9C0(void);

/* Memory card footprint: kind 2, size in 1 KB clusters of the header-padded data plus the icon. */
extern "C" void func_0019D3D0(void *self, int *kind, unsigned int *clusters)
{
    *kind = 2;
    Saver *s = D_005857DC;
    VEntry *e = &s->vt[2];
    unsigned int size = e->fn((char *)s + e->delta);
    *clusters = (((size + 0x47) & ~0x3F) + 0x3FF) >> 10;
    *clusters += (func_0019D9C0() + 0x3FF) >> 10;
}
