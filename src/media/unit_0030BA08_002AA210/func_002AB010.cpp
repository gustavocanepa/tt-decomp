/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);
extern "C" String *func_0050F1B0(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_004A8368(const char *s) throw();

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

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_005A4850);
    assign(str, s);
}

extern char D_005F14D8[]; /* "" */
extern "C" void func_002AA2A0(char *buf, const char *s) throw();
extern "C" void func_002AAAC8(char *buf, char *a, char *b) throw();
extern "C" int func_002AB6F0(String *s);

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline u32 length(const String *str) { return rep(str)->len; }
static inline bool empty(const String *str) { return length(str) == 0; }
static inline char *rep_data(StringRep *r) { return (char *)(r + 1); }
static inline char &rep_at(StringRep *r, u32 i) { return rep_data(r)[i]; }
static inline void terminate(const String *str) { rep_at(rep(str), length(str)) = 0; }
static inline const char *c_str(const String *str) {
    if (length(str) == 0)
        return D_005F14D8;
    terminate(str);
    return rep_data(rep(str));
}
static inline void copy(String *str, const String *src) {
    str->dat = grab(rep(src));
}

extern "C" String *func_002AB010(String *ret, const String *a, String *b) {
    if (!empty(b)) {
        if (!func_002AB6F0(b)) {
            copy(ret, b);
        } else {
            char buf1[0x400];
            char buf2[0x400];
            char buf3[0x400];
            func_002AA2A0(buf1, c_str(a));
            func_002AA2A0(buf2, c_str(b));
            func_002AAAC8(buf3, buf1, buf2);
            construct(ret, buf3);
        }
    } else {
        copy(ret, b);
    }
    return ret;
}
