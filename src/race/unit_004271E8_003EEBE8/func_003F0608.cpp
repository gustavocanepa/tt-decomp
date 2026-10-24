struct St { char p[8]; float x, y, z; int pad[2]; int ok; };
struct Ent { int p0; char *t4; char *t8; };
struct Tab { char p[0x10]; char *ents; };
struct A { int f0; Tab *f4; };
extern "C" void func_003F2178(St *s, int a, int b);
extern "C" float func_003F1AF0(char *p, float t);
extern "C" float func_003F4AB8(char *p, float t);
extern "C" float func_003F39A0(Ent *e, int i, St *s, float t);
extern "C" float func_003F39E8(Ent *e, int i, St *s, float t, float u);

extern "C" int func_003F0608(A *self, int arg1, int arg2, int arg3, int arg4, int count, float *o1, float *o2, float *o3, float f0, float f1) {
    St st;
    int idx;
    int sel;
    if (self->f4 == 0) return 0;
    if (arg2 >= 0) {
        idx = arg2;
        sel = 1;
    } else if (arg3 >= 0) {
        idx = arg3;
        sel = 0;
    } else {
        return 0;
    }
    Ent *e = (Ent *)(self->f4->ents + arg1 * 0x10);
    float t;
    if (sel) t = func_003F4AB8(e->t4 + (idx << 5), f0);
    else t = func_003F1AF0(e->t8 + (idx << 5), f0);
    func_003F2178(&st, arg4, count);
    if (sel) func_003F39A0(e, idx, &st, t);
    else func_003F39E8(e, idx, &st, t, f1);
    if (st.ok != 0) switch (count) {
    case 1:
        *o1 = st.x;
        return 1;
    case 2:
        *o1 = st.x;
        *o2 = st.y;
        return 1;
    case 3:
        *o1 = st.x;
        *o2 = st.y;
        *o3 = st.z;
        return 1;
    }
    return 0;
}
