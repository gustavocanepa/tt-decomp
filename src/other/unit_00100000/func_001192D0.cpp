/* Returns basic_string<char>(the text a virtual of the global object G (D_005797E0) writes into a local buffer) by value, or an empty string when G is null: the gcc 2.96 bastring.h
 * constructors from const char * (nilRep.grab() + assign(s, strlen(s)) = replace(0, npos, s, n),
 * func_0050F1B0) and the default one (nilRep.grab() alone). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s);
struct VEntry { short delta; short index; const char *(*fn)(void *self, void *buf); };
struct Global { char pad[0x64]; VEntry *vtbl; };
extern Global *D_005797E0;
static inline const char *vcall(Global *o, void *buf) {
    VEntry *e = o->vtbl + 0x63;
    return e->fn((char *)o + e->delta, buf);
}

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

extern "C" String *func_001192D0(String *ret) {
    char buf[0x10];
    Global *g = D_005797E0;
    if (g) {
        construct(ret, vcall(g, buf));
        return ret;
    }
    construct(ret);
    return ret;
}
