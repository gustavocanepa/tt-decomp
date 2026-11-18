/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Request {
    int a, b;
    char name[0x40];
    int c, d, e, f, g;
};
struct State { char pad[0x3E4]; Request request; char pad440[0x5C]; int ready; };
extern State *D_0059834C;
extern "C" int func_005038D8(void);
extern "C" char *func_004F7B74(char *, const char *);
extern "C" void func_004AEB30(void *);
extern "C" void func_004B7A28(int a, int b, const char *name, int c, int d, int e, int f, int g) {
    State *s = D_0059834C;
    Request *r = &s->request;
    int enabled = func_005038D8();
    r->a = a;
    r->b = b;
    if (name) func_004F7B74(r->name, name);
    else r->name[0] = 0;
    r->c = c;
    r->d = d;
    r->e = e;
    r->f = f;
    r->g = g;
    s->ready = 1;
    if (enabled) __asm__ volatile("ei");
    func_004AEB30((char *)s + 4);
}
