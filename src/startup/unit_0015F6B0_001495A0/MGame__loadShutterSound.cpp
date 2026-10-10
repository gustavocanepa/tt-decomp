typedef unsigned int u32;

struct StringRep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
};

extern const char D_005E1BD8[]; /* "" */

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
            return D_005E1BD8;
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
extern "C" void func_0042EAE8(const char *s);

extern "C" void MGame__loadShutterSound(void *self, void *a1, int count, void *arg)
{
    if (count > 0) {
        Handle h;
        func_002ADC48(&h, arg);
        func_0042EAE8(func_002AFE68(h.p)->c_str());
        func_002ADBF0(&h, 2);
    } else {
        func_0042EAE8(0);
    }
}
