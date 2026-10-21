typedef float f32;

void func_00303450(void *arg0) {
    char *v = (char *)arg0 + 0x104;
    f32 t2 = *(f32 *)(v + 0x5E8);
    f32 t3 = *(f32 *)(v + 0x5E0);
    f32 t0 = *(f32 *)((char *)arg0 + 0x56C) * 111.1111f;
    f32 r;
    f32 t4;
    f32 s;
    f32 u;

    if (t2 < t3) {
        r = t2 + t0;
        *(f32 *)(v + 0x5E8) = r;
        if (t3 < r) {
            *(f32 *)(v + 0x5E8) = t3;
        }
    } else {
        r = t2 - t0;
        *(f32 *)(v + 0x5E8) = r;
        if (r < t3) {
            *(f32 *)(v + 0x5E8) = t3;
        }
    }
    t4 = *(f32 *)(v + 0x580);
    s = *(f32 *)(v + 0x57C);
    u = s + ((((*(f32 *)(v + 0x574) - t4) * 200.0f) - (s * 20.0f)) * 0x1.111110p-6f);
    *(f32 *)(v + 0x57C) = u;
    *(f32 *)(v + 0x580) = t4 + u * 0x1.111110p-6f;
}
