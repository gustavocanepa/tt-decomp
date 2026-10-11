struct In {
    char pad[0x20];
    virtual int v00();
    virtual int v01();
};
struct Out { char pad[0x60]; In *p; };
extern "C" int func_0055AC08(Out *arg0) {
    return arg0->p->v01();
}
