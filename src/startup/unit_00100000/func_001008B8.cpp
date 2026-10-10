/* dynamic_cast<D &>(*o).method(): __dynamic_cast (GT4MC__FileGT4GameData__loadInstance) with the type_info functions
   func_0050EB20 / func_0050F058, bad_cast (exception__structor_2) when it fails, then the virtual call
   at slot 0x88 of the result. Written out by hand like func_002F67E8. */
struct VEntry {
    short delta;
    short index;
    void *fn;
};

struct Obj {
    char pad[0x64];
    VEntry *vtbl;
};

extern "C" char func_0050EB20[];
extern "C" char func_0050F058[];
extern "C" Obj *GT4MC__FileGT4GameData__loadInstance(void *tf, void *target, int boff, void *top, void *src, Obj *o);
extern "C" void exception__structor_2(void) __attribute__((noreturn));

extern "C" void func_001008B8(Obj *o) {
    VEntry *e = o->vtbl;
    Obj *d = GT4MC__FileGT4GameData__loadInstance(e->fn, func_0050EB20, 0, (char *)o + e->delta, func_0050F058, o);
    if (d == 0)
        exception__structor_2();
    VEntry *v = (VEntry *)((char *)d->vtbl + 0x88);
    ((void (*)(void *))v->fn)((char *)d + v->delta);
}
