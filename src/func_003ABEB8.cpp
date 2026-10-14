/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj;
struct VF { short delta; short index; float (*fn)(void *, int); };
struct VI { short delta; short index; int (*fn)(void *, int); };
struct VObj { int pad; VF *vt; };
struct Obj { int m0; int m4; float m8[2]; int m10[2]; float m18; int m1C; };
extern "C" VObj *func_00376740(int);
extern "C" void func_003ABEB8(Obj *o)
{
    int i = 0;
    int flag = 0;
    o->m1C = 0;
    float best = 100.0f;
    o->m4 = o->m4 + 1;
    VObj *c = func_00376740(o->m0);
    do {
        VF *e = (c->vt + 3);
        float t = e->fn((char *)c + e->delta, i);
        o->m8[i] = t;
        VI *e2 = (VI *)(c->vt + 4);
        int r = e2->fn((char *)c + e2->delta, i);
        o->m10[i] = r;
        if (i == 0) {
            if (t < best) best = t;
            VI *e3 = (VI *)(c->vt + 4);
            flag = e3->fn((char *)c + e3->delta, 0) != 0 ? 1 : flag;
        }
        i++;
    } while (i < 2);
    if (best > 8.0f) {
        float v = o->m18 - 0.016666666f;
        o->m18 = v;
        if (v < 0.0f) { o->m18 = 8.0f; flag = 1; }
    } else {
        o->m18 = best;
    }
    if (flag) o->m1C = 1;
}
