/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Mat44 { f32 m[16]; } __attribute__((aligned(8)));

#define E(i, j) ((f32 *)((char *)&t + k##j))[(i)] = a->m[(i)] * ((const f32 *)((const char *)b + k##j))[0] + a->m[(i) + 4] * b->m[(j) * 4 + 1] + a->m[(i) + 8] * b->m[(j) * 4 + 2] + a->m[(i) + 12] * b->m[(j) * 4 + 3]
extern "C" void func_00317A18(Mat44 *out, Mat44 *a, Mat44 *b) {
    Mat44 t;
    int k0=0, k1=16, k2=32, k3=48;
    E(0,0); E(0,1); E(0,2); E(0,3);
    E(1,0); E(1,1); E(1,2); E(1,3);
    E(2,0); E(2,1); E(2,2); E(2,3);
    E(3,0); E(3,1); E(3,2); E(3,3);
    *out = t;
}
