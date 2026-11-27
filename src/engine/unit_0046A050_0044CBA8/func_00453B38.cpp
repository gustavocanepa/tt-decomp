/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x, y, z; };
inline float get(const float *p) { return *p; }
struct Mat { float m[3][3]; };
extern "C" void func_00453B38(Vec3 *out, const Mat *m, const Vec3 *v) {
    const float *pz = &v->z;
    const float *py = &v->y;
    out->x = m->m[0][0] * get(&v->x) + m->m[1][0] * get(py) + m->m[2][0] * get(pz);
    out->y = m->m[0][1] * get(&v->x) + m->m[1][1] * get(py) + m->m[2][1] * get(pz);
    out->z = m->m[0][2] * get(&v->x) + m->m[1][2] * get(py) + m->m[2][2] * get(pz);
}
