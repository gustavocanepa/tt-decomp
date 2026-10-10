struct Obj;
extern "C" void func_004A4D68(Obj *o);
extern "C" void func_004A4DD8(Obj *o);
extern "C" void func_004A4F90(Obj *o);
extern "C" void func_0047E690(void *p, Obj *o);
extern "C" void func_0047EE88(Obj *o);

struct Obj {
    char pad0[0x50];
    void *m50;
    char pad54[0x60 - 0x54];
    void *m60;
    char pad64[0x80 - 0x64];
    int state;
};

extern "C" void func_0047EDC8(Obj *o) {
    func_004A4D68(o);
    bool b = o->state != 3;
    if (b) {
        o->state = 3;
        func_004A4F90(o);
    }
    if (o->m50)
        func_0047E690(o->m50, o);
    void *p = o->m60;
    func_004A4DD8(o);
    if (p)
        func_0047EE88(o);
}
