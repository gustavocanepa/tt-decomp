struct E { char pad0[4]; float a, b, c; union { short sh; float fl; } u; char pad14[8]; float d, e, f; };
struct Q { char pad[0xC]; short n; };
struct O { int a, b, c, d; };
extern "C" int func_00438C38(Q *p, int x);
extern "C" void func_004368A8(O *o, Q *p, int n);
extern "C" E *func_00436968(O *o, int i);

extern "C" void func_00438D58(Q *p, int x, float *o1, float *o2, int *o3) {
    if (p->n != 0) {
        O o;
        int i = func_00438C38(p, x);
        E *e;
        func_004368A8(&o, p, 4);
        e = func_00436968(&o, i);
        o1[0] = e->a;
        o1[1] = e->b;
        o1[2] = e->c;
        o2[0] = e->d;
        o2[1] = e->e;
        o2[2] = e->f;
        *o3 = e->u.sh;
    }
}
