/* Returns basic_string<char>(func_0040EE48(G->p6C->p70)) by value, or an empty string when the global G (D_005797E0) is null: the gcc 2.96 bastring.h
 * constructors from const char * (nilRep.grab() + assign(s, strlen(s)) = replace(0, npos, s, n),
 * func_0050F1B0) and the default one (nilRep.grab() alone). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s);
struct Inner { char pad[0x70]; void *p70; };
struct Global { char pad[0x6C]; Inner *p6C; };
extern Global *D_005797E0;
extern "C" const char *func_0040EE48(void *p);

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

extern "C" String *func_001191F0(String *ret) {
    Global *g = D_005797E0;
    if (g) {
        construct(ret, func_0040EE48(g->p6C->p70));
        return ret;
    }
    construct(ret);
    return ret;
}
