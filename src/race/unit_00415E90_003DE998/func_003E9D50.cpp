/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
extern "C" {
f32 func_003E9D50(f32 p0, f32 p1, f32 p2, f32 p3, f32 p4, f32 p5, f32 p6, f32 p7, f32 s0, f32 s8, f32 s10, f32 s18) {
    f32 t21 = p3 * p7;
    f32 t11 = s8 * p4;
    f32 t20 = p6 * p4;
    f32 t7 = s8 * p7;
    f32 t10 = p3 * s10;
    f32 t6 = p6 * s10;
    f32 t18 = p6 * p1;
    f32 t3 = s8 * p1;
    f32 t19 = p0 * p7;
    f32 t1 = p0 * s10;
    f32 t15 = p3 * p1;
    f32 t12 = p0 * p4;
    return ((((((((((((((((((t11 * p2) - (t20 * p2)) + (t21 * p2)) - (t7 * p2)) - (t10 * p2)) + (t6 * p2) + (t18 * p5)) - (t3 * p5)) - (t19 * p5)) + (t7 * p5) + (t1 * p5)) - (t6 * p5)) - (t15 * s0)) + (t3 * s0) + (t12 * s0)) - (t11 * s0)) - (t1 * s0)) + (t10 * s0) + (t15 * s18)) - (t18 * s18)) - (t12 * s18)) + (t20 * s18) + (t19 * s18)) - (t21 * s18);
}
}
