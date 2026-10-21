struct Ref { char *p; int pad[3]; };
struct Obj { char *p; int pad[3]; };
struct VE { short delta; short idx; int (*fn)(void *); };
struct Hold { char *vt; int a; int b; };

extern "C" void func_00251620(void *arg0, int arg1) throw();
extern "C" void func_00251678(void *arg0, int arg1) throw();
extern "C" void func_001DF1C8(void *a, void *b);
extern "C" void func_001DF1F8(void *a, int b);
extern "C" void func_00202758(void *a, void *b);
extern "C" void func_00202788(void *a, int b);
extern "C" void func_00257760(void *a, int b, int c, int d);

static inline int *st(int *p, int v) { *p = v; return p; }

extern "C" void func_00252680(void *self, int a1, int count, Hold *a3) {
    if (count == 3) {
        Obj o;
        Ref r1;
        Ref r2;
        int t1;
        int t2;
        func_00251678(&o, a1);
        Ref *p1 = &r1;
        func_001DF1C8(p1, st(&t1, a3->a));
        int v2 = a3->b;
        int *q2 = &t2;
        Ref *p2 = &r2;
        *q2 = v2;
        func_00202758(p2, q2);
        char *obj = a3->vt;
        a3 = (Hold *)o.p;
        VE *ve = (VE *)(*(char **)(obj + 4) + 0x68);
        func_00257760(a3, ve->fn(obj + ve->delta), (int)p1->p, (int)p2->p);
        func_00202788(p2, 2);
        func_001DF1F8(p1, 2);
        func_00251620(&o, 2);
    }
}
