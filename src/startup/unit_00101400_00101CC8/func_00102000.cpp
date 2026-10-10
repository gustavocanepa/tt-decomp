struct Lock { char pad[0x30]; };
struct Owner;

struct Listener {
    virtual void v0();
    virtual void v1();
    virtual void update(Owner *o, float dt);
};

struct Owner {
    char pad[0x6C];
    Lock lock;
    Listener *listener;
    int active;
    int padA4;
    float time;
};

extern "C" void func_004A4D68(Lock *l);
extern "C" void func_004A4DD8(Lock *l);

extern "C" void func_00102000(Owner *o, float dt) {
    if (o->active) {
        func_004A4D68(&o->lock);
        o->listener->update(o, dt);
        o->time += dt;
        func_004A4DD8(&o->lock);
    }
}
