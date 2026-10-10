/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);

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
};

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};
extern char D_006019A8[];
extern char D_006019B0[];

struct Entry { const char *name; f32 value; };
extern Entry D_00586780[];
extern "C" Entry *func_005694C0(const char *key, Entry *table, s32 count);
extern "C" void func_0043D658(Val *);
extern "C" void func_004A6448(const char *, ...);

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006019A8;
    s.terminate();
    return s.data();
}

extern "C" Val func_00443008(const String &name) {
    Entry *e = func_005694C0(c_str(name), D_00586780, 8);
    if (e)
        return Val((f32)e->value);
    Val t;
    func_0043D658(&t);
    func_004A6448(D_006019B0, c_str(name));
    return t;
}
