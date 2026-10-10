/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);

/* the script value: type 1 is nil; func_0043D510 releases the payload and sets nil */
struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_0043D3B8(this, &o); }
    ~Val() { func_0043D510(this); }
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

struct Method { const char *name; s32 f4; Val (*fn)(Obj *); };
extern Method D_00586668[];
extern "C" Method *func_00569250(const char *key, Method *table, s32 count);
extern "C" Val *func_0044B170(void *, const String &);
extern "C" Val func_004476D0(Obj *, const String &);

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006016F8;
    s.terminate();
    return s.data();
}

extern "C" Val func_004424D8(Obj **self, const String &name) {
    Method *m = func_00569250(c_str(name), D_00586668, 15);
    if (m)
        return m->fn(*self);
    Val *p = func_0044B170(vcall3(*self), name);
    if (p)
        return *p;
    Val r = func_004476D0(*self, name);
    return r;
}
