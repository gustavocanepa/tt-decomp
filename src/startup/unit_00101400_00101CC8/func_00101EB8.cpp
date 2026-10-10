struct Obj;

struct Listener {
    virtual void v0();
    virtual void v1(Obj *o);
};

struct Mutex {
    int w[2];
};

struct Obj {
    char pad[0x6C];
    Mutex mutex;
    char pad74[0x28];
    Listener *listener;
    char padA0[8];
    int mA8;
    int mAC;
};

extern "C" void func_004A4D68(Mutex *m);
extern "C" void func_004A4DD8(Mutex *m);
extern "C" void func_00109608(Obj *o);

extern "C" void func_00101EB8(Obj *o) {
    Mutex *m = &o->mutex;
    func_004A4D68(m);
    o->mA8 = 0;
    o->mAC = 0;
    o->listener->v1(o);
    func_004A4DD8(m);
    func_00109608(o);
}
