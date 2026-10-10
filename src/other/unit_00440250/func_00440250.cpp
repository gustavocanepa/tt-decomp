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
extern char D_006016C8[];
extern "C" void func_0043D6E8(Val *, const char *);
extern "C" void func_0043DEA0(Val *, void *);

struct Obj { char pad[0x60]; String str; s32 f64; };

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006016C8;
    s.terminate();
    return s.data();
}

extern "C" Val func_00440250(Obj *o) {
    Val t;
    if (o->f64)
        func_0043D6E8(&t, c_str(o->str));
    else
        func_0043DEA0(&t, o);
    return t;
}
