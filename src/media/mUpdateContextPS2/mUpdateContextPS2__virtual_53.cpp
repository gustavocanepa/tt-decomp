/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Str { char *p; };
struct Rep { int len, cap, ref, sel; };
extern char D_005E8D90[], D_005E8DF0[];
extern unsigned int D_00586A68;
extern "C" void *func_0045D898(void *);
extern "C" const char *func_00455930(unsigned int);
extern "C" int func_004A6500(char *, const char *, ...);
extern "C" void func_0045D948(void *, const char *);
extern "C" void func_001C5C30(void *, void *, void *) throw();
extern "C" void func_0045D8D8(void *, int);
static inline const char *c_str(Str *s) {
    int len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_005E8D90;
    s->p[len] = 0;
    return s->p;
}
extern "C" void mUpdateContextPS2__virtual_53(void *self, Str *a, Str *b) {
    int obj[4];
    char buf[0x80];
    func_0045D898(obj);
    const char *middle = func_00455930(D_00586A68);
    func_004A6500(buf, D_005E8DF0, c_str(a), middle, c_str(b));
    func_0045D948(obj, buf);
    func_001C5C30(self, b, obj);
    func_0045D8D8(obj, 2);
}
