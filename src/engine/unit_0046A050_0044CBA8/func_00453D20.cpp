/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x, y, z, w; };
inline float get(const float *p) { return *p; }
struct Mat { float m[4][4]; };
extern "C" void func_00453D20(Vec4 *out, const Mat *m, const Vec4 *v) {
    const float *pw = &v->w;
    const float *pz = &v->z;
    const float *py = &v->y;
    out->x = m->m[0][0] * get(&v->x) + m->m[1][0] * get(py) + m->m[2][0] * get(pz) + m->m[3][0] * get(pw);
    out->y = m->m[0][1] * get(&v->x) + m->m[1][1] * get(py) + m->m[2][1] * get(pz) + m->m[3][1] * get(pw);
    out->z = m->m[0][2] * get(&v->x) + m->m[1][2] * get(py) + m->m[2][2] * get(pz) + m->m[3][2] * get(pw);
    out->w = m->m[0][3] * get(&v->x) + m->m[1][3] * get(py) + m->m[2][3] * get(pz) + m->m[3][3] * get(pw);
}
