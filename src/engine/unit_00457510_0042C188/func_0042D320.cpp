/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { int f0; const char *name; int pad[4]; };
struct Tab { Ent *base; int pad[3]; };
extern int D_00585F1C;
extern int D_00585F18;
extern char D_0076A058[];
extern "C" int func_0042CEF0(int) throw() __attribute__((const));
extern "C" void func_0042CF18(int, int, float, int) throw();
extern "C" Tab *func_0042D140(Tab *, int) throw();
extern "C" void func_004A4D68(char *);
extern "C" void func_004A4DD8(char *);
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" void func_0042D320(int a0, int a1, int a2, float f)
{
    int need = 0;
    int k, cur;
    func_004A4D68(D_0076A058);
    if (a1 != D_00585F1C) {
        need = 1;
    } else if (a1 != -1) {
        if (a1 & 0x1000) {
            need = 1;
        } else {
            k = func_0042CEF0(a0);
            cur = D_00585F18;
            if (k != func_0042CEF0(cur)) {
            set:
                need = 1;
            } else {
                Tab x;
                Tab y;
                func_0042D140(&x, cur);
                func_0042D140(&y, a0);
                switch (k) {
                case 1:
                    {
                        Ent *e0 = x.base;
                        e0 += D_00585F1C;
                        Ent *e1 = y.base;
                        e1 += a1;
                        need = func_004A8268(e0->name, e1->name) != 0;
                    }
                    break;
                case 0:
                    need = (D_00585F18 ^ a0) != 0;
                    break;
                }
            }
        }
    } else {
        goto set;
    }
    if (need) func_0042CF18(a0, a1, f, a2);
    func_004A4DD8(D_0076A058);
}
