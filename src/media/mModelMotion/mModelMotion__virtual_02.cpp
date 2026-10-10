/* Returns basic_string<char>(the object's virtual name getter (vtable slot at +0x20)) by value: the gcc 2.96 bastring.h constructor from
 * const char * = nilRep.grab() (clone when selfish, else ++ref) + assign(s, strlen(s))
 * = replace(0, npos, s, n) (func_0050F1B0). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s);
struct VEntry { short delta; short index; const char *(*fn)(void *self); };
struct VObj { int pad; VEntry *vtbl; };
static inline const char *vcall(VObj *o) {
    VEntry *e = o->vtbl + 4;
    return e->fn((char *)o + e->delta);
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

extern "C" String *mModelMotion__virtual_02(String *ret, VObj *obj) {
    construct(ret, vcall(obj));
    return ret;
}
