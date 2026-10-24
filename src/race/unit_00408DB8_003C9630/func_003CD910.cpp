/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct V3 { f32 x, y, z; };
struct V4 { f32 x, y, z, w; };
struct T { char pad[0x14]; f32 f14; };
struct S {
    char pad[8]; f32 f8, fc, f10;
    V3 a, b, c;
    V3 d; f32 f44;
    f32 f48; T *t;
};
extern "C" f32 pglmRandom(void);

extern "C" void func_003CD910(S *s, V3 *p1, V3 *p2, V3 *p3, V4 *p4, f32 fp, T *t) {
    s->a.x = p1->x;
    s->a.y = p1->y;
    s->a.z = p1->z;
    s->b.x = p2->x;
    s->b.y = p2->y;
    s->b.z = p2->z;
    s->c.x = p3->x;
    s->c.y = p3->y;
    s->c.z = p3->z;
    s->d.x = p4->x;
    s->d.y = p4->y;
    s->d.z = p4->z;
    f32 w = p4->w;
    s->f48 = fp;
    s->t = t;
    s->f44 = w;
    s->f44 = w + t->f14;
    s->f8 = pglmRandom() * 0x1.921fb4p+2f;
    s->fc = pglmRandom() * 0x1.921fb4p+2f;
    s->f10 = pglmRandom() * 0x1.921fb4p+2f;
}
