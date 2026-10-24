/* compiler: ee-gcc2.96-no-strict-aliasing */
struct St { int a; char *b; int c; int d; };
struct Ent { int p0; short x, y, z; int p1; };
struct Tab { char p[0x10]; char *ents; char p2[8]; Ent *e; };
struct A { int f0; Tab *f4; };
extern char D_005D76E0[];
extern "C" int func_003F1860(A *self, int idx);
extern "C" float func_003F39A0(char *e, int i, St *s, float t);
extern "C" float func_003F39E8(char *e, int i, St *s, float t, float u);

extern "C" int func_003F0C80(A *self, int arg1, int arg2) {
    St st;
    int result = 0;
    int sel;
    if (self->f0 == 0) return 0;
    if (self->f4 == 0) return 0;
    if (func_003F1860(self, arg1) == 1) goto found;
fail:
    return 0;
found:
    {
        {
            Tab *t = self->f4;
            Ent *e = (Ent *)(arg1 * 0x10 + (int)t->e);
            int y = e->y;
            int table = e->x;
            int a0 = e->z;
            if (y >= 0) {
                arg1 = y;
                sel = 1;
            } else {
                if (a0 < 0) goto fail;
                arg1 = a0;
                sel = 0;
            }
            char *ent = t->ents + table * 0x10;
            st.a = 0;
            st.b = D_005D76E0;
            st.c = self->f0;
            st.d = arg2;
            if (sel) func_003F39A0(ent, arg1, &st, 0.0f);
            else func_003F39E8(ent, arg1, &st, 0.0f, 0.0f);
            return 1;
        }
        return 0;
    }
    return result;
}
