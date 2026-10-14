/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { int a; int b; };
struct Arr { int n; Ent e[1]; };
struct S { char pad0[0x14]; int i14; int i18; };
extern "C" float func_00378888(void *, int, void *) throw();
extern "C" void func_00378FD8(Arr *, int, int, int, S *, int) throw();
extern "C" void func_00379200(Arr *a, int a1, int a2, int a3, S *s, int t1)
{
    int idx[3];
    int cur = s->i18;
    idx[0] = cur - 1;
    idx[1] = cur;
    idx[2] = cur + 1;
    if (idx[0] < 0) idx[0] = a->n - 1;
    if (idx[2] >= a->n) idx[2] = 0;
    float f = func_00378888(&a->e[idx[1]], a3, &a->e[idx[0]]);
    if (f < func_00378888(&a->e[idx[1]], a3, &a->e[idx[2]])) cur = idx[2];
    s->i14 = cur;
    func_00378FD8(a, a1, a2, a3, s, t1);
}
