/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep2 {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    inline char *grab();
    static void operator delete(void *p, u32 n);
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep2) + res);
    }
};

extern "C" char *strobe__toUpper(Rep2 *r);
extern "C" void func_004A45D0(void *p);
extern Rep2 D_005A4C58;

inline void Rep2::operator delete(void *p, u32 n) { func_004A45D0(p); }

inline char *Rep2::grab() {
    if (selfish)
        return strobe__toUpper(this);
    ++ref;
    return data();
}

extern "C" u32 func_004A8368(const char *s);


struct String2;
extern "C" String2 *func_00550E18(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String2 {
    char *dat;
    Rep2 *rep() const { return (Rep2 *)dat - 1; }
    String2() {}
    String2(const char *s) : dat(D_005A4C58.grab()) { assign(s); }
    String2(const String2 &str) : dat(str.rep()->grab()) {}
    u32 length() const { return rep()->len; }
    char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    ~String2() { rep()->release(); }
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_00550E18(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_004A8368(s)); }
    String2 &operator=(const String2 &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};


extern "C" void func_00443F98(void *);
extern "C" char *func_00440198(void *);
extern char D_005D9E18[];
extern "C" void func_00443F98(void *);
extern "C" char *func_00440198(void *);
extern char D_005D9E18[];
struct Sub { const char *s; u32 n; };
struct Elem { char pad[0x24]; Sub sub; char pad2[0x34 - 0x2C]; };
struct Hdr { char pad[0x60]; Elem *elems; };
struct Info { char pad[6]; short idx; };
struct Base {
    Hdr *hdr;
    Info *info;
    char pad[0x54 - 8];
    String2 s54;
    char pad2[4];
    Base() __asm__("func_00443F98");
};
struct Obj : Base {
    char *vt;
    String2 s60;
    s32 f64;
    Obj() __asm__("func_0043FFB8");
};
Obj::Obj() : vt(D_005D9E18), s60(func_00440198(this)) {
    f64 = 0;
    Elem *e = (Elem *)((char *)hdr->elems + info->idx * 0x34);
    if (s54.length() == 0) {
        Sub *sp = &e->sub;
        if (sp->n != 0) {
            {
                String2 t(sp->s);
                s54 = t;
            }
            f64 = 1;
        }
    }
}
