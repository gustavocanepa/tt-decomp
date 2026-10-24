/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x5C]; void *f5C; void *f60; char pad64[0xDC-0x64]; int fDC; int *fE0; };
struct Callback { void (*fn)(Obj *); Obj *self; };
struct Buffer { void *data; int size; };
extern char D_00777640[];
extern char D_00778640[];
extern char D_00598C40[];
extern "C" void func_004C19C0(Obj *);
extern "C" void func_004C1A48(Obj *);
extern "C" int func_004A58E0(unsigned int, int);
extern "C" void *func_004A53A0(int);
extern "C" void *func_004A56C8(Callback *, Buffer *, void *);
extern "C" void func_004A5618(void *);
extern "C" void func_004C1FC0(void *);
extern "C" void func_004C1608(Obj *o) {
    Callback cb;
    Buffer b2;
    Buffer b1;
    int unused[4];
    o->fDC = 0;
    o->fE0 = &o->fDC;
    Buffer *buf1 = &b1;
    cb.fn = func_004C19C0;
    cb.self = o;
    buf1->data = D_00777640;
    buf1->size = 0x1000;
    o->f60 = func_004A56C8(&cb, buf1, func_004A53A0(func_004A58E0(3, -1)));
    func_004A5618(o->f60);
    Buffer *buf2 = &b2;
    cb.fn = func_004C1A48;
    cb.self = o;
    buf2->data = D_00778640;
    buf2->size = 0x1000;
    o->f5C = func_004A56C8(&cb, buf2, func_004A53A0(func_004A58E0(3, 1)));
    func_004A5618(o->f5C);
    func_004C1FC0(D_00598C40);
}
