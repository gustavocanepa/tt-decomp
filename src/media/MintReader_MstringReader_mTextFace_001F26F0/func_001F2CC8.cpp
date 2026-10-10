/* Returns basic_string<char>(buf) by value, buf filled by func_00259388(obj->p104, buf, 0x100, a, b):
 * the gcc 2.96 bastring.h constructor from const char * = nilRep.grab() + assign(s, strlen(s))
 * = replace(0, npos, s, n) (func_0050F1B0). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s);
struct Obj { char pad[0x12C]; void *p104; };
extern "C" void func_00259388(void *p, char *buf, u32 size, int a, int b);

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

extern "C" String *func_001F2CC8(String *ret, Obj *obj, int a, int b) {
    char buf[0x100];
    func_00259388(obj->p104, buf, 0x100, a, b);
    construct(ret, buf);
    return ret;
}
