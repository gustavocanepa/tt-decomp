typedef int s32;

struct Listener_004295B0 {
    virtual void v01(void *e);
};

struct Obj_004295B0 {
    char pad0[8];
    void *m8;
    Listener_004295B0 *mC;
};

extern "C" s32 func_0041FCD8(void *a, void *e, s32 n);

extern "C" void func_003F0BF0(Obj_004295B0 *o, void *e) {
    if (func_0041FCD8(o->m8, e, 0)) {
        o->mC->v01(e);
    }
}
