struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};
struct VObj {
    char pad[0x64];
    VEntry *vtbl;
};
static inline void vcall3(VObj *o)
{
    VEntry *e = &o->vtbl[3];
    e->fn((char *)o + e->delta);
}
extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" char D_0061BC70[];
extern VObj *D_00578EB0;
extern int D_00578EB4;
extern int D_00578EB8;

extern "C" void func_00100E38(int v)
{
    func_004A4D68(D_0061BC70);
    if (D_00578EB0)
        vcall3(D_00578EB0);
    D_00578EB4 = v;
    D_00578EB8 = 1;
    func_004A4DD8(D_0061BC70);
}
