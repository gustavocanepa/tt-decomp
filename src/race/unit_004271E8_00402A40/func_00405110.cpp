extern "C" void func_004AFB90(int color, float *h, float *s, float *v);

extern "C" float func_00405110(int color) {
    float h, s, v;
    float r;
    func_004AFB90(color, &h, &s, &v);
    if (0.25f <= s) {
        h += 120.0f;
        if (360.0f < h)
            h -= 360.0f;
        r = h + 152.0f;
    } else {
        r = (1.0f - v) * 152.0f;
    }
    return r * 0.001953125f;
}
