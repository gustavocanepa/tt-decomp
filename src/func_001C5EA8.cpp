/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Stat { char pad[0x10]; int size; char pad2[0x2c]; };
struct Obj0 { char pad[16]; };
extern char D_005E8D90[];
extern "C" void func_0045D898(Obj0 *);
extern "C" void func_0045D8D8(Obj0 *, int);
extern "C" void func_0045D9E8(Obj0 *, void *);
extern "C" int func_004B82B8(int);
extern "C" int func_004B8F30(int, const char *, Stat *, int, int);
extern "C" void func_004B9420(int, const char *, void *, int, int);
extern "C" int func_004BA058(int);
extern "C" void func_004A45D0(int) throw();
extern "C" int func_004A4690(int, int);
extern "C" void func_001C5C30(void *, Str *, Obj0 *) throw();

static inline const char *c_str(Str *s) {
    int n = *(int *)(s->p - 16);
    if (n == 0) return D_005E8D90;
    s->p[n] = 0;
    return s->p;
}

extern "C" void mUpdateContextPS2__virtual_54(void *self, Str *name) {
    Obj0 o;
    Stat st;
    func_0045D898(&o);
    const char *path = c_str(name);
    if (func_004B8F30(0, path, &st, 0, 1) != 0 || func_004B82B8(0) != 0 || func_004BA058(0) != 1) {
        func_0045D8D8(&o, 2);
        return;
    }
    int sz = st.size;
    sz = (sz + 0x3F) & ~0x3F;
    void *buf = (void *)func_004A4690(0x40, sz);
    func_004B9420(0, path, buf, 0, sz);
    if (func_004B82B8(0) != 0) {
        func_004A45D0((int)buf);
        func_0045D8D8(&o, 2);
        return;
    }
    func_0045D9E8(&o, buf);
    func_001C5C30(self, name, &o);
    func_0045D8D8(&o, 2);
}
