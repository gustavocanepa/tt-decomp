struct Vec2 { float x, y; };
struct Poly { int n; Vec2 pts[1]; };
struct Vec3 { float x, y, z; };
extern "C" void func_00474E90(void *, void *);
extern "C" void func_00378620(Poly *p) {
    Vec3 cur, prev;
    int i = 0;
    char *base = (char *)p + 4;
    prev.y = 0.0f;
    int n = p->n;
    int off = n * 8 - 8;
    char *last = base + off;
    float xlast = *(float *)last;
    float zlast = ((Poly *)((char *)p + off))->pts[0].y;
    prev.x = xlast;
    prev.z = zlast;
    if (n > 0) {
        Vec2 *v = (Vec2 *)base;
        do {
            float x = v->x;
            float z = v->y;
            v++;
            cur.x = x;
            cur.z = z;
            i++;
            cur.y = 0.0f;
            func_00474E90(&cur, &prev);
            prev.x = cur.x;
            prev.y = cur.y;
            prev.z = cur.z;
        } while (i < p->n);
    }
}
