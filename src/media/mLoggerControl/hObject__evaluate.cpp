struct Res;
extern "C" void func_002C0FE8(Res *r); /* add a reference */
extern "C" void func_002C1050(Res *r); /* drop a reference */

/* A reference-counting pointer, named after its destructor (func_002A75A8) so that
   _$_13func_00309378 resolves. */
struct func_002A75A8 {
    Res *p;
    func_002A75A8(const func_002A75A8 &o);
    ~func_002A75A8();
    func_002A75A8 &operator=(const func_002A75A8 &o)
    {
        if (this != &o) {
            Res *np = o.p;
            if (np)
                func_002C0FE8(np);
            if (p)
                func_002C1050(p);
            p = np;
        }
        return *this;
    }
};

struct Key {
    int id;
    Key(int i) : id(i) {}
};

extern "C" func_002A75A8 func_002A7578(const Key &k);

extern "C" void hObject__evaluate(int v, func_002A75A8 *out)
{
    *out = func_002A7578(Key(v));
}
