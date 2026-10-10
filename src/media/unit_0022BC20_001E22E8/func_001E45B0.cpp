extern "C" void func_002C0FE8(void *obj);
extern "C" void func_002C1050(void *obj);

struct Ref {
    void *p;
    int pad[3];
    void assign(const Ref &o)
    {
        if (this != &o) {
            void *np = o.p;
            if (np)
                func_002C0FE8(np);
            if (p)
                func_002C1050(p);
            p = np;
        }
    }
};

struct Obj {
    char pad0[0x6D8];
    Ref ref;
};

extern "C" void func_001FBD88(Ref *r, const int *value);
extern "C" void func_001FBDB8(Ref *r, int in_chrg);

extern "C" void func_001E45B0(Obj *self, int value)
{
    Ref *r = &self->ref;
    Ref tmp;
    int v = value;
    func_001FBD88(&tmp, &v);
    r->assign(tmp);
    func_001FBDB8(&tmp, 2);
}
