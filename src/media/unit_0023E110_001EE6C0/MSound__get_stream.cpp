extern "C" void *func_001EDC38(void *h);
extern "C" void func_001EDBE0(void *h, int in_chrg);
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
    char pad0[0x14];
    Ref ref;
};

struct Handle {
    Owner *p;
    int pad[3];
};

extern "C" void MSound__get_stream(Ref *out)
{
    Handle h;
    func_001EDC38(&h);
    out->assign(h.p->ref);
    func_001EDBE0(&h, 2);
}
