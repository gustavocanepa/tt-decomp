/* Returns basic_string<char>(func_0040CF70(func_0011C668(a2))) when the global D_005797E0 is set and func_0011C628(a2)->0x1D0 is 0, else an empty string (bastring.h: default ctor = nilRep.grab(), (const char *) ctor = grab + assign(s, strlen(s)), copy ctor = rep()->grab(), dtor = rep()->release() -> func_00326798(p, sizeof(Rep) + res, 4, heap name)) */
typedef unsigned int u32;
typedef int s32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };
struct Heap { const char *name; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s);
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
struct G { char pad[0x1D0]; s32 flag; };
extern void *D_005797E0;
extern "C" G *func_0011C628(void *a);
extern "C" void *func_0011C668(void *a);
extern "C" const char *func_0040CF70(void *a);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_0050F0F0(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_0050F1B0(str, 0, (u32)-1, s, n);
}

static inline String &assign(String *str, const char *s) {
    return assign(str, s, func_004A8368(s));
}

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_005A4850);
    assign(str, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_005A4850);
    assign(str, s);
}

static inline void construct(String *str) {
    str->dat = grab(&D_005A4850);
}

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline void copy(String *str, const String *src) { str->dat = grab(rep(src)); }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(StringRep) + ((StringRep *)ptr)->res); }
static inline void release(StringRep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(String *str) { release(rep(str)); }

extern "C" String *func_00119408(String *ret, void *a1, void *a2) {
    if (D_005797E0 && func_0011C628(a2)->flag == 0) {
        construct(ret, func_0040CF70(func_0011C668(a2)));
        return ret;
    }
    construct(ret);
    return ret;
}
