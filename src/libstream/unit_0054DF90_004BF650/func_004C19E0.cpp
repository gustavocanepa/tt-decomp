struct Obj {
    char pad[0x18];
    char m18[1];
};

extern char D_00777580[];

extern "C" int func_004FA710(Obj *o);
extern "C" void func_004FE770(Obj *o, int v);
extern "C" void func_004C1BC0(void);
extern "C" void func_004FE808(void *p, int tag, void (*fn)(void), void *buf, int a, int b, Obj *o);
extern "C" void func_004FEC20(Obj *o);

extern "C" void func_004C19E0(Obj *o) {
    func_004FE770(o, func_004FA710(o));
    func_004FE808(o->m18, 0x42535550, func_004C1BC0, D_00777580, 0, 0, o);
    func_004FEC20(o);
}
