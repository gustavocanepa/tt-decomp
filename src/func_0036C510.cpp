/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Link { short next; short pad; const char *text; };
struct Table { union { Link links[1]; struct { int pad[2]; int head; int func_00575DA0; int x; int y; } h; } u; };
extern char D_00585CC8[];
extern char D_005F6BB8[];
extern "C" void func_00104C88(void *);
extern "C" void func_00478C98(int);
extern "C" void func_004155A8(void *, const char *);
extern "C" void func_00415BB0(void *, float, float, float, float);
extern "C" void func_00415860(void *, int, int);
extern "C" void func_00415D18(void *, const char *, ...);
extern "C" void func_0036C510(Table *t, void *a) {
    func_00104C88(a);
    func_00478C98(5);
    func_00478C98(8);
    func_004155A8(D_00585CC8, D_005F6BB8);
    func_00415BB0(D_00585CC8, 0.8f, 0.8f, 0.8f, 0.8f);
    int x = t->u.h.x;
    int i = t->u.h.head;
    int y = t->u.h.y;
    while (i >= 0) {
        Link *e = &t->u.links[i];
        int old_y = y;
        y += 18;
        func_00415860(D_00585CC8, x, old_y);
        func_00415D18(D_00585CC8, e->text);
        i = e->next;
    }
}
