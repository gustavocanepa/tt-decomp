/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x, y, z; };
inline float get(const float *p) { return *p; }
struct Mat { float m[4][4]; };
extern "C" void func_00453C20(Vec3 *out, const Mat *m, const Vec3 *v) {
    const float *pz = &v->z;
    const float *py = &v->y;
    out->x = m->m[0][0] * get(&v->x) + m->m[1][0] * get(py) + m->m[2][0] * get(pz) + m->m[3][0];
    out->y = m->m[0][1] * get(&v->x) + m->m[1][1] * get(py) + m->m[2][1] * get(pz) + m->m[3][1];
    out->z = m->m[0][2] * get(&v->x) + m->m[1][2] * get(py) + m->m[2][2] * get(pz) + m->m[3][2];
}
