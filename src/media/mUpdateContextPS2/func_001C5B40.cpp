/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001C5B10(void *);
struct Callback { void (*fn)(void *); void *self; char pad[0x18]; };
struct Args { int a; int b; char pad[8]; };
extern void *D_0057ABEC;
extern "C" int func_004A58E0(unsigned int, int);
extern "C" void *func_004A53A0(void *);
extern "C" void *func_004A56C8(void *, void *, void *);
extern "C" int func_004A5618(void *);
extern "C" void func_001C5B40(char *self, int a, int b) {
    Callback cb;
    Args args;
    *(int *)(self + 0x118) = 0;
    cb.fn = func_001C5B10;
    cb.self = self;
    Args *p = &args;
    p->a = a;
    p->b = b;
    void *r = func_004A56C8(&cb, p, func_004A53A0((void *)func_004A58E0(1, 1)));
    D_0057ABEC = r;
    func_004A5618(r);
}
