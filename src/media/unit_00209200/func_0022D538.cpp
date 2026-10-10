extern "C" void func_0022CEE8(void *h);
extern "C" void func_0022E3E8(void *h, int in_chrg);

struct Handle {
    void *p;
    int pad[3];
    Handle() { func_0022CEE8(this); }
    ~Handle() { func_0022E3E8(this, 2); }
};

struct Ref {
    Ref(const int &v, int flags) __asm__("func_0022C0B8");
    Ref(void *p) __asm__("func_0022E908");
    ~Ref();
    void *p;
    int pad[3];
};

Ref func_0022D538()
{
    Handle h;
    if (h.p == 0)
        return Ref(0, 0);
    return Ref(h.p);
}
