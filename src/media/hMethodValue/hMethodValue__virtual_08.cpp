struct Res;
extern "C" void func_002C0FE8(Res *r); /* add a reference */
extern "C" void func_002C1050(Res *r); /* drop a reference */

/* A reference-counting pointer, named after its destructor (func_002A1E40) so that
   _$_13func_00302A80 resolves. */
struct func_002A1E40 {
    Res *p;
    func_002A1E40(const func_002A1E40 &o);
    ~func_002A1E40();
    func_002A1E40 &operator=(const func_002A1E40 &o)
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

extern "C" func_002A1E40 func_002A2450(int b, int a);

extern "C" void hMethodValue__virtual_08(int a, func_002A1E40 *out, int b)
{
    *out = func_002A2450(b, a);
}
