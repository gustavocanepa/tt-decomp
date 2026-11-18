struct Obj {
    virtual int v00();
    virtual int v01();
};
struct Holder { Obj *p; };
extern "C" int func_0047B4F8(Holder *arg0) {
    return arg0->p->v01() != 0;
}
