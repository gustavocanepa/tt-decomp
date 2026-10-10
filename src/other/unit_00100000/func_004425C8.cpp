/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);
extern "C" Val *func_0043D3E0(Val *, const Val *);

/* the script value: type 1 is nil, 6 a float; func_0043D510 releases the payload and sets nil */
struct Val {
    s32 type;
    union {
        s32 v;
        f32 f;
    };
    Val() : type(1) {}
    Val(f32 x) : type(6) { f = x; }
    Val(const Val &o) { func_0043D3B8(this, &o); }
    ~Val() { func_0043D510(this); }
    Val &operator=(const Val &o) { func_0043D3E0(this, &o); return *this; }
    bool isUndef() const { return type == 2; }
};

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};
extern char D_006016F8[];
#define EMPTY D_006016F8

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return EMPTY;
    s.terminate();
    return s.data();
}

struct Ctx { char pad[0x164]; s32 f164; };
struct VEntry { short delta; short index; void *(*fn)(void *); };
struct Obj { char pad[0x5C]; VEntry *vtbl; };

static inline void *vcall3(Obj *o) {
    VEntry *e = o->vtbl + 3;
    return e->fn((char *)o + e->delta);
}

struct Entry { const char *name; Val (*fn)(Obj *self, s32 z, s32 c); };
extern Entry D_00586720[];
extern "C" Entry *func_005692D0(const char *key, Entry *table, s32 count);
extern "C" Val func_0044B1E0(void *, const String &, s32, s32, Ctx *);

extern "C" Val func_004425C8(Obj **self, const String &name, s32 z, s32 w, Ctx *ctx) {
    Entry *e = func_005692D0(c_str(name), D_00586720, 12);
    if (e)
        return e->fn(*self, z, ctx->f164);
    Val t;
    t = func_0044B1E0(vcall3(*self), name, z, w, ctx);
    /* two identical returns, as in the original (the undefined case probably held a debug print
       that the release build compiles to nothing) */
    if (!t.isUndef())
        return t;
    return t;
}
