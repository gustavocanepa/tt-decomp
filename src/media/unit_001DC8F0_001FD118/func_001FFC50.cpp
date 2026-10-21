/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Elem { char pad[0xC4]; unsigned short counter; };
struct Obj { char pad[0xDC]; short start; short count; };
static inline int increment(unsigned short *c) { int old=*c; *c=old+1; return old; }
extern "C" int func_001FFC50(Obj *p, int i) {
    Elem *e = (Elem *)(i * 2 + (int)p);
    unsigned short *counter = &e->counter;
    int result = 0;
    if (*counter != 0) {
        int start = p->start;
        int old=increment(counter);
        result = old == start;
        if (*counter >= p->start + p->count)
            *counter = (unsigned short)p->start;
    }
    return result;
}
