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
extern "C" void func_0043D6E8(Val *, const char *);

struct Obj { char pad[0x54]; String str; };

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006016F8;
    s.terminate();
    return s.data();
}

extern "C" Val func_00441718(Obj *o) {
    Val t;
    func_0043D6E8(&t, c_str(o->str));
    return t;
}
