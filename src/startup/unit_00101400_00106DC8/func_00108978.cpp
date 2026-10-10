/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj_00109748 {
    char pad0[0x5C];
    bool m5C;
    s32 m60;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
};

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);

extern "C" void func_00108978(Obj_00109748 *o) {
    func_004A4D68(o);
    bool b = !o->m5C;
    if (b) {
        o->m5C = b;
        o->m60 = 0;
        o->v10();
    }
    func_004A4DD8(o);
}
