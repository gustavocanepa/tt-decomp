/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);

/* the script value: type 1 is nil; func_004768C0 releases the payload and sets nil */
struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_004768C0(this); }
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

struct VEntry { short delta; short index; void *(*fn)(void *); };
struct Obj { char pad[0x5C]; VEntry *vtbl; };

static inline void *vcall3(Obj *o) {
    VEntry *e = o->vtbl + 3;
    return e->fn((char *)o + e->delta);
}

struct Method { const char *name; void (*fn)(void *, s32); void *getter; };
extern Method D_00586668[];
extern "C" Method *func_00569250(const char *key, Method *table, s32 count);
extern "C" s32 func_00447738(void *, const String &, s32);
extern "C" int func_0044B188(void *, const String &, s32, s32);

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006016F8;
    s.terminate();
    return s.data();
}

extern "C" s32 func_00442358(Obj **self, const String &name, s32 c, s32 z) {
    Method *m = func_00569250(c_str(name), D_00586668, 15);
    if (m) {
        m->fn(*self, c);
        return 1;
    }
    if (func_00447738(*self, name, c) != 0)
        return 1;
    return func_0044B188(vcall3(*self), name, c, z) != 0;
}
