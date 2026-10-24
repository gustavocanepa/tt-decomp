extern "C" void *func_0028B8B0(void *h);
extern "C" void func_0028B858(void *h, int in_chrg);
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
    char pad0[0xB8];
    Ref ref;
};

struct Handle {
    Owner *p;
    int pad[3];
};

extern "C" void func_0028BCF0(Ref *out)
{
    Handle h;
    func_0028B8B0(&h);
    out->assign(h.p->ref);
    func_0028B858(&h, 2);
}
