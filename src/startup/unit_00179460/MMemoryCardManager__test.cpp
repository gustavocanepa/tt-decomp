typedef unsigned int u32;

struct StringRep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
};

extern const char D_005E2AC8[]; /* "" */

/* gcc 2.96 bastring.h basic_string<char>: c_str() terminates the data unless it is empty. */
struct String {
    char *dat;
    StringRep *rep() const { return (StringRep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const
    {
        if (length() == 0)
            return D_005E2AC8;
        terminate();
        return data();
    }
};

struct Handle {
    void *p;
    int pad[3];
};

extern "C" void func_002ADC48(Handle *h, void *arg);
extern "C" void func_002ADBF0(Handle *h, int in_chrg);
extern "C" String *func_002AFE68(void *p);
struct Obj {
    void *p;
    int pad[3];
    void *get() const { return p; }
};

extern "C" void func_00156538(Obj *o, void *arg);
extern "C" void func_001564E0(Obj *o, int in_chrg);
extern "C" void func_00159508(void *p, const char *s);

extern "C" void MMemoryCardManager__test(void *self, void *key, int count, void *arg)
{
    if (count > 0) {
        Handle h;
        func_002ADC48(&h, arg);
        Obj o;
        func_00156538(&o, key);
        void *p = o.get();
        func_00159508(p, func_002AFE68(h.p)->c_str());
        func_001564E0(&o, 2);
        func_002ADBF0(&h, 2);
    }
}
