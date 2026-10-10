/* Returns basic_string<char>(buf) by value, buf formatted with vsprintf (func_004A68B0) from
 * (fmt, ...): the gcc 2.96 bastring.h constructor from const char * = nilRep.grab()
 * + assign(s, strlen(s)) = replace(0, npos, s, n) (func_0050F1B0). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s);
extern "C" int func_004A68B0(char *buf, const char *fmt, __builtin_va_list args);

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

extern "C" String *func_002BC748(String *ret, const char *fmt, ...) {
    __builtin_va_list args;
    char buf[0x200];
    __builtin_stdarg_start(args, fmt);
    func_004A68B0(buf, fmt, args);
    construct(ret, buf);
    return ret;
}
