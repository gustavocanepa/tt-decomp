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

struct Source {
    char pad0[0x20];
    void *value;
};

extern "C" Source *func_00199FD8(void);
extern "C" void func_0015A528(Ref *r, void *value);
extern "C" void func_001596F8(Ref *r, int in_chrg);

extern "C" void MMemoryCardManager__getPrintList(Ref *out)
{
    Ref tmp;
    func_0015A528(&tmp, func_00199FD8()->value);
    out->assign(tmp);
    func_001596F8(&tmp, 2);
}
