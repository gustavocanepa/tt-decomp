/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[8]; void *p8; int padc; void *p10; char pad14[0x40]; int magic; int flags; int pad5c; void *p60; void (*cb)(); int pad68; char data[0x20]; };
extern "C" void func_004C13C0();
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void *exception__structor_0(int);
extern "C" void rbuf__structor_0(void *, int);
extern "C" void func_004C26B0(void *);
extern "C" void func_004CEE70(void *);
extern "C" void func_004CEB90(void *, int);
extern "C" void func_004CEEC8(void *);
extern "C" void func_004C11F8(Obj *o) {
    void **handle = &o->p8;
    o->magic = 0x534d5550;
    o->flags = 1;
    o->cb = func_004C13C0;
    o->p10 = 0;
    func_004F6678(o->data, 0, 0x20);
    void *p = exception__structor_0(0x44);
    rbuf__structor_0(p, 0x20);
    *handle = p;
    func_004C26B0(p);
    func_004CEE70(o);
    func_004CEB90(o->p60, 0);
    func_004CEEC8(o);
}
