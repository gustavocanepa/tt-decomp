/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct V3 {
    f32 x, y, z;
};

extern "C" V3 *func_00473980(s32);
extern "C" void func_0046D810(s32, V3 *, s32, s32, s32, s32);

extern "C" void func_003CE390(s32 a, f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1) {
    V3 *p = func_00473980(8);
    f32 e = 0x1.999998p-6f;
    p[0].x = x0 - e; p[0].y = y0; p[0].z = z0;
    p[1].x = x1 - e; p[1].y = y1; p[1].z = z1;
    p[2].x = x0; p[2].y = y0; p[2].z = z0 - e;
    p[3].x = x1; p[3].y = y1; p[3].z = z1 - e;
    p[4].x = x0 + e; p[4].y = y0; p[4].z = z0;
    p[5].x = x1 + e; p[5].y = y1; p[5].z = z1;
    p[6].x = x0; p[6].y = y0; p[6].z = z0 + e;
    p[7].x = x1; p[7].y = y1; p[7].z = z1 + e;
    p[8].x = x0 - e; p[8].y = y0; p[8].z = z0;
    p[9].x = x1 - e; p[9].y = y1; p[9].z = z1;
    func_0046D810(10, p, 0, a, 0, 0);
}
