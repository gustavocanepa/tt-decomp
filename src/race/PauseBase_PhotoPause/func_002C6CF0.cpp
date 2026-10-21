/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair1 { char pad[0xE44]; int a; int b; };
struct Pair2 { char pad[0xE4C]; int a; int b; };
extern "C" void func_0031AB68(int, int);
extern "C" void func_0031C6C0(int, int);
extern "C" int func_0033B028(void *);
extern "C" void *func_002C6290(void *) throw();
extern "C" int func_002C6298(void *) throw();
extern "C" int PhotoPause__deleteAnimInst(void *) throw();
extern "C" void func_002C6CF0(void *arg0) {
    func_0031AB68(func_002C6298(arg0), 0);
    func_0031C6C0(func_002C6298(arg0), 0);
    Pair1 *p = (Pair1 *)func_002C6290(arg0);
    p->a = 0;
    p->b = 0;
    Pair2 *q = (Pair2 *)func_002C6290(arg0);
    q->a = 0;
    q->b = 0;
    func_0033B028(func_002C6290(arg0));
    PhotoPause__deleteAnimInst(arg0);
}
