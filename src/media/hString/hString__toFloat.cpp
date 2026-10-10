typedef int s32;
typedef unsigned int u32;
extern char D_005F1720[];
#define EMPTY D_005F1720

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return EMPTY;
    s.terminate();
    return s.data();
}

struct Obj { char pad[0x10]; String name; };
extern "C" s32 func_004F4DC0(const char *);
extern "C" void func_004B4B10(s32);

extern "C" void hString__toFloat(Obj *o) {
    func_004B4B10(func_004F4DC0(c_str(o->name)));
}
