struct Obj;

struct Listener {
    virtual void v00();
    virtual void attached(Obj *o);
};

struct Obj {
    char pad[0x6C];
    char lock[0x30];
    Listener *listener;
};

extern "C" Listener *D_005794AC;
extern "C" void func_004A4D68(void *m);
extern "C" void func_004A4DD8(void *m);

extern "C" void func_00101E48(Obj *o, Listener *l)
{
    if (!l)
        l = D_005794AC;
    o->listener = l;
    func_004A4D68(o->lock);
    o->listener->attached(o);
    func_004A4DD8(o->lock);
}
