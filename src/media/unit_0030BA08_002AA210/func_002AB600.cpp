/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct StringRep { u32 len, res, ref, selfish; };
struct String { char *dat; };
extern StringRep D_005A4850;
extern "C" char *func_0050F0F0(StringRep *);
extern "C" String *func_0051C3A0(String *, u32, u32, const String *, u32, u32);
extern "C" u32 func_00529CE0(const String *, char, u32);
static inline char *grab(StringRep *r) {
    if (r->selfish) return func_0050F0F0(r);
    ++r->ref;
    return (char *)(r + 1);
}
static inline StringRep *rep(const String *s) { return (StringRep *)s->dat - 1; }
static inline void copy(String *r, const String *s) { r->dat = grab(rep(s)); }
static inline void construct(String *r, const String *s, u32 pos, u32 n) {
    r->dat = grab(&D_005A4850);
    func_0051C3A0(r, 0, (u32)-1, s, pos, n);
}
extern "C" String *func_002AB600(String *ret, const String *s) {
    if (rep(s)->len != 0) {
        u32 pos = func_00529CE0(s, '.', (u32)-1);
        if (pos != (u32)-1) {
            construct(ret, s, pos, (u32)-1);
            return ret;
        }
    }
    copy(ret, s);
    return ret;
}
