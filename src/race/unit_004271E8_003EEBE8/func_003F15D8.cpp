/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { int f0; float f4; int p8; float fC; unsigned short f10; unsigned short p12; int p14; int f18; int f1C; };
struct Out { int f0; float f4; float f8; int fC; int f10; int f14; };
struct Rec { char p[4]; short a; short p6; short b; char q[6]; };
struct Tab { char p[8]; char *t8; int pc; };
struct A { char p[0x10]; Tab *tab; char q[8]; Rec *recs; };
extern "C" int func_003F1A08(char *s);
extern "C" Item *func_003F1A10(char *s, int i);
extern "C" int func_004A8268(int a, int b) throw();

extern "C" int func_003F15D8(Out *out, A *self, int idx, int key) {
    Item *it;
    if (key != 0) {
        if (idx >= 0) goto start;
        return 0;
    found:
        out->f0 = it->f18;
        {
            float t = it->f4;
            float len = it->fC;
            out->f4 = t;
            out->f8 = t + len;
        }
        out->fC = it->f10;
        out->f10 = it->f1C;
        out->f14 = it->f0;
        return 1;
    start:
        {
            Rec *r = (Rec *)(idx * 16 + (int)self->recs);
            int b = r->b;
            int i;
            if (b >= 0) {
                int group = r->a;
                Tab *g = self->tab;
                g += group;
                char *base = g->t8 + (b << 5);
                int n = func_003F1A08(base);
                for (i = 0; i < n; i++) {
                    it = func_003F1A10(base, i);
                    if (it != 0 && it->f18 != 0 && func_004A8268(it->f18, key) == 0) goto found;
                }
            }
        }
    }
    return 0;
}
