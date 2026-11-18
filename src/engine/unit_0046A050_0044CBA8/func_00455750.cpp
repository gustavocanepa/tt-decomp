extern "C" float func_00455750(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float s0, float s8, float s10, float s18, float s20, float s28, float s30, float s38) {
    float m0 = a0 * a5 - a4 * a1;
    float n0 = s10 * s38 - s30 * s18;
    float m1 = a0 * s8 - s0 * a1;
    float n1 = a6 * s38 - s30 * a7;
    float m2 = a0 * s28 - s20 * a1;
    float n2 = a6 * s18 - s10 * a7;
    float m3 = a4 * s8 - s0 * a5;
    float n3 = a2 * s38 - s30 * a3;
    float m4 = a4 * s28 - s20 * a5;
    float n4 = a2 * s18 - s10 * a3;
    float m5 = s0 * s28 - s20 * s8;
    float n5 = a2 * a7 - a6 * a3;
    return m0 * n0 - m1 * n1 + m2 * n2 + m3 * n3 - m4 * n4 + m5 * n5;
}
