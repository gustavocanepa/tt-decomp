typedef unsigned int u32;

struct Heap { const char *name; };

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s) throw();

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep) + res);
    }
};

extern "C" char *func_005C2560(Rep *r);
extern Rep D_00659FA8;

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

struct String;
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String {
    char *dat;
    char pad[0xC];
    Rep *rep() const { return (Rep *)dat - 1; }
    String() : dat(D_00659FA8.grab()) {}
    String(const String &str) : dat(str.rep()->grab()) {}
    ~String() { rep()->release(); }
    u32 length() const { return rep()->len; }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &append(const char *s, u32 n) { return replace(length(), 0, s, n); }
    String &append(const char *s) { return append(s, func_0057F260(s)); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String &operator=(const char *s) { return assign(s); }
    String &operator=(const String &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};

inline String operator+(const String &lhs, const char *rhs) {
    String str(lhs);
    str.append(rhs);
    return str;
}


typedef int s32;
typedef unsigned char u8;
struct VEntry {
    short delta;
    short index;
    void *fn;
};
#define VCALL1(R, o, off, a) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *, ...))e_->fn)((char *)(o) + e_->delta, a); })

extern "C" void func_002931C8(void *arg0, int arg1);
extern "C" void *func_002944D0(void *ret, void *self, s32 x);
extern "C" void func_00295180(void *arg0);
extern "C" void func_002A75A8(void *arg0, s32 arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1) throw();
extern "C" void func_002ADC48(void *arg0) throw();
extern "C" void func_002B0C60(void *a, void *b, void *c);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

struct H {
    void *p;
    char pad[12];
};
struct Val {
    s32 p;
    char pad[12];
};
struct Str {
    char *p;
    char pad[0xC];
};

extern "C" void func_002AF048(s32 *arg0, s32 arg1, s32 n, s32 *p) {
    s32 newVal;
    s32 oldVal;
    if (n > 0) {
        Val h;
        Val w;
        Val r;
        func_002ADC48(&h);
        Val *pw = &w;
        func_00295180(pw);
        {
            s32 i;
            for (i = 0; i < n; i++) {
                Val *pt = &r;
                func_002944D0(pt, (void *)pw->p, (s32)p);
                func_002A75A8(pt, 2);
                p++;
            }
        }
        Val *pr = &r;
        func_002B0C60(pr, (void *)h.p, pw);
        if (arg0 != &pr->p) {
            newVal = pr->p;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_002ADBF0(pr, 2);
        func_002931C8(pw, 2);
        func_002ADBF0(&h, 2);
    }
}
