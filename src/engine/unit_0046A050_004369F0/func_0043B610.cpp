/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Ent { s32 a; s32 b; s32 c; };
struct Arr {
    Ent *data;
    s32 n;
    Ent *begin() { return data; }
    Ent *end() { return data + n; }
};
struct Obj { char pad[0x10]; Arr arr; };
struct Cmp {
    char c;
    s32 len;
    Cmp(s32 l) : len(l) {}
};
extern "C" s32 func_0043B550(const char *, s32, Ent *) throw();
extern "C" s32 func_004A8368(const char *) throw();
extern "C" Ent *func_005682C0(Ent *, Ent *, const char *const &, Cmp, s32 *);
static inline s32 *distance_type(Ent *const &) { return (s32 *)0; }
static inline Ent *lower_bound(Ent *first, Ent *last, const char *const &val, Cmp comp) {
    return func_005682C0(first, last, val, comp, distance_type(first));
}
extern "C" s32 func_0043B610(Obj *self, const char *key) {
    s32 len = func_004A8368(key);
    Ent *it = lower_bound(self->arr.begin(), self->arr.end(), key, Cmp(len));
    if (it == self->arr.end() || func_0043B550(key, len, it) != 0) return -1;
    return it->a;
}
