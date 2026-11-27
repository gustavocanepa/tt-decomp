struct Ent { float a, b, c; int pad; unsigned d; };
struct Obj { char p0[4]; void *o4; char p1[0x70]; Ent e[3]; };
extern "C" float func_003180D8(void *, float);
extern "C" float func_005357F8(void *);

extern "C" void func_003A74F8(Obj *o, int idx, int arg2, float f0, float f1, float f2, float f3, float f4)
{
    Ent *e = (Ent *)((char *)o + idx * 0x14 + 0x90);
    float dt = 0.016666666f;
    unsigned t = e->d & ~0xFFu;
    e->d = t;
    if (((unsigned char *)&e->d)[1] != 0) {
        e->c = e->c - dt;
        if (arg2 != 0) {
            e->b = 0.0f;
        } else {
            float v = e->b + dt;
            e->b = v;
            if (f2 < v) {
                e->b = 0.0f;
                e->d = t & 0xFFFF00FFu;
            }
        }
        if (e->c < 0.0f) {
            e->b = 0.0f;
            e->d = e->d & 0xFFFF00FFu;
        }
    } else {
        float v = e->a + dt;
        e->a = v;
        if (v <= 0.0f) e->a = 0.0f;
        if (e->a >= 30.0f) e->a = 30.0f;
        if (arg2 != 0) {
            float w = e->b + dt;
            e->b = w;
            if (f1 < w) {
                e->c = f4;
                e->b = 0.0f;
                e->d = (e->d & 0xFFFF00FFu) | 0x100;
                float r = func_003180D8((char *)o + 0xCC, e->a / 30.0f) * f0;
                if (func_005357F8(o->o4) < r) {
                    e->c = f3;
                    e->a = 0.0f;
                    e->d = (e->d & ~0xFFu) | 1;
                }
            }
        } else {
            e->b = 0.0f;
        }
    }
}
