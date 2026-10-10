typedef int s32;
typedef unsigned int u32;

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);
extern "C" void func_0043D3B8(Val *, const Val *);

struct Entry { const char *name; s32 type; };
extern "C" Entry *func_00568D38(const char *key, Entry *table, s32 count);
extern Entry D_005865E8[];
extern char D_00601468[];

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
    const char *c_str() const { if (length() == 0) return D_00601468; terminate(); return data(); }
};

extern "C" Val *func_0043D2E8(Val *ret, const String &name, char *base) {
    Val tmp;
    Entry *e;
    tmp.type = 1;
    e = func_00568D38(name.c_str(), D_005865E8, 16);
    if (e) {
        s32 type = e->type;
        func_0043D510(&tmp);
        tmp.type = type;
        if (e->type == 9)
            tmp.v = (s32)(base + 0x40);
    } else {
        func_0043D510(&tmp);
    }
    func_0043D3B8(ret, &tmp);
    func_0043D510(&tmp);
    return ret;
}
