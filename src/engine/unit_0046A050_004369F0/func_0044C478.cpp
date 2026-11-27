/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script method dispatch over a one-entry table (D_00586988), like func_0047C778: the named entry's
   function is called with (self, c, z); an unknown name returns a fresh value (func_0043D658). */
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
extern char D_00602228[];
#define EMPTY D_00602228

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return EMPTY;
    s.terminate();
    return s.data();
}
struct Entry { const char *name; Val (*fn)(void *self, s32 c, s32 z); };
extern Entry D_00586988[];
extern "C" Entry *func_0056CE30(const char *key, Entry *table, s32 count);
extern "C" void func_0043D658(Val *);

extern "C" Val func_0044C478(void *self, const String &name, s32 z, s32 c) {
    Entry *e = func_0056CE30(c_str(name), D_00586988, 1);
    if (e)
        return e->fn(self, c, z);
    Val t;
    func_0043D658(&t);
    return t;
}
