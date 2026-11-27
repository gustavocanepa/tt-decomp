/* compiler: ee-gcc2.96-no-strict-aliasing */
struct In { char pad[0x3C]; volatile int f3c; };
struct H { In *p; };
struct O { char pad[0xB4]; H h; };
extern "C" void func_00182A18(O *, void *) throw();
extern "C" void func_001829B0();
extern "C" int func_001A6840(In *, void (*)(), void *);
static inline In *get(H *h) { return h->p; }
static inline bool busy(H *h) { return get(h)->f3c != 0; }
extern "C" int func_00182D50(O *o, void *a1)
{
    H *h = &o->h;
    if (busy(h)) return 0;
    func_00182A18(o, a1);
    return func_001A6840(get(h), func_001829B0, o);
}
