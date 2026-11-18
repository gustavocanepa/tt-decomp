extern "C" void *func_00123F58(void *h);
extern "C" void func_00123F00(void *h, int in_chrg);
extern "C" void func_002C0FE8(void *obj);
extern "C" void func_002C1050(void *obj);

/* Reference-counted pointer with the inline assignment of 002F8B00. */
struct Ref {
    void *p;
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

struct Owner {
    char pad0[0x310];
    Ref ref;
};

struct Handle {
    Owner *p;
    int pad[3];
};

extern "C" void func_00125D30(Ref *out)
{
    Handle h;
    func_00123F58(&h);
    out->assign(h.p->ref);
    func_00123F00(&h, 2);
}
