struct V3 { float x, y, z; };
struct Q { V3 v[4]; int a0, a1, b0, b1; };
extern "C" Q *func_00473980(int);
extern "C" void func_0046D810(int, void *, int, void *, int, int);
extern "C" void func_003F5758(int a, int b, float f0, float f1, float f2, float f3) {
    Q *q = func_00473980(4);
    volatile Q *p = q;
    p->v[0].x = f0; p->v[0].y = f1; p->v[0].z = 0;
    p->v[1].x = f2; p->v[1].y = f1; p->v[1].z = 0;
    p->v[2].x = f0; p->v[2].y = f3; p->v[2].z = 0;
    p->v[3].x = f2; p->v[3].y = f3; p->v[3].z = 0;
    p->a0 = a; p->a1 = a; p->b0 = b; p->b1 = b;
    func_0046D810(4, q, 0, &q->a0, 0, 0);
}
