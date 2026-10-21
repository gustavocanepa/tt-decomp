/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
extern "C" void func_004509C0(f32 *out, const f32 *v) {
    int k = 4, k2 = 8, k3 = 12;
    f32 *o1 = (f32 *)((char *)out + k);
    f32 *o2 = (f32 *)((char *)out + k2);
    f32 *o3 = (f32 *)((char *)out + k3);
    f32 m[4];
    m[0] = out[0];
    m[1] = o1[0];
    m[2] = o2[0];
    m[3] = o3[0];
    const f32 *v3 = (const f32 *)((const char *)v + k3);
    const f32 *m3 = (const f32 *)((const char *)m + k3);
    const f32 *v1 = (const f32 *)((const char *)v + k);
    const f32 *m2 = (const f32 *)((const char *)m + k2);
    const f32 *m1 = (const f32 *)((const char *)m + k);
    const f32 *v2 = (const f32 *)((const char *)v + k2);
    out[0] = ((v3[0] * m[0] + m3[0] * v[0]) - v1[0] * m2[0]) + m1[0] * v2[0];
    o1[0] = ((v3[0] * m1[0] + m3[0] * v1[0]) + v[0] * m2[0]) - m[0] * v2[0];
    o2[0] = ((m[0] * v1[0] - v[0] * m1[0]) + v3[0] * m2[0]) + m3[0] * v2[0];
    o3[0] = ((m3[0] * v3[0] - m[0] * v[0]) - m1[0] * v1[0]) - m2[0] * v2[0];
}
