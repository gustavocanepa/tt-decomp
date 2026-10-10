/* Returns basic_string<char>(a float formatted with sprintf (func_004A6500) into a local buffer) by value: the gcc 2.96 bastring.h constructor from
 * const char * = nilRep.grab() (clone when selfish, else ++ref) + assign(s, strlen(s))
 * = replace(0, npos, s, n) (func_0050F1B0).
 * Written with the promotion as an explicit fptodp call (fmt loaded first, kept in $s0); passing
 * the float straight to the variadic call also matches but leaves the libcall unchecked. */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s);
struct Obj { char pad[0x10]; float value; };
extern char D_005F0E50[];
extern "C" double func_004B4C18(float f); /* fptodp: the float -> double vararg promotion */
extern "C" int func_004A6500(char *buf, const char *fmt, ...);

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

extern "C" String *func_0029B0E0(String *ret, Obj *obj) {
    char buf[0x20];
    const char *fmt = D_005F0E50;
    double d = func_004B4C18(obj->value);
    func_004A6500(buf, fmt, d);
    construct(ret, buf);
    return ret;
}
