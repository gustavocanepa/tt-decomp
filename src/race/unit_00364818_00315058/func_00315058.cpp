/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Vec3 { f32 x, y, z; };

extern "C" f32 func_004A5C50(f32);
extern "C" f32 func_004A5D18(f32) throw();

extern "C" void func_00315058(Vec3 *a0, Vec3 *a1, Vec3 *a2, f32 a, f32 b, f32 c) {
    f32 sa = func_004A5D18(a);
    f32 ca = func_004A5C50(a);
    f32 sb = func_004A5D18(b);
    f32 cb = func_004A5C50(b);
    f32 sc = func_004A5D18(c);
    f32 cc = func_004A5C50(c);
    f32 t1, t2, t3, t4, t6, t9, t0;
    t2 = cc * sa;
    t1 = sc * sa;
    t0 = cc * ca;
    t3 = (cc * cb) - (t1 * sb);
    t4 = (sc * cb) + (t2 * sb);
    t9 = t2 * cb;
    t6 = (cc * sb) + (t1 * cb);
    a1->z = -ca * sb;
    a1->x = t3;
    a1->y = t4;
    a0->z = sa;
    a0->x = -sc * ca;
    a0->y = t0;
    a2->z = ca * cb;
    a2->y = (sc * sb) - t9;
    a2->x = t6;
}
