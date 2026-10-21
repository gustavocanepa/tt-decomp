/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Point { Vec pos; char pad[0x24]; signed char flag; char tail[3]; };
struct Owner { int a; void *course; };
struct Pair { short a,b; void clear() { a = -1; b = -1; } };
struct Search { char pad[0x30]; Pair id; };
extern "C" void func_0034B378(void *, void *) throw();
extern "C" void *func_0034C5E8(void *);
extern "C" int GT4Course__RunwayData__search(void *, void *, const Vec *);
static inline void update(Owner *o, Point *p) {
    Search s;
    Vec v;
    s.id.clear();
    v.x = p->pos.x;
    v.y = p->pos.y + 5.0f;
    v.z = p->pos.z;
    if (GT4Course__RunwayData__search(func_0034C5E8(o->course), &s, &v)) {
        p->flag = 0;
        func_0034B378(p, &s);
        return;
    }
    p->flag = 1;
}
extern "C" void func_0034B470(Owner *o, Point *p) {
    for (int i = 0; i < 4; i++) {
        update(o, &p[i]);
    }
}
