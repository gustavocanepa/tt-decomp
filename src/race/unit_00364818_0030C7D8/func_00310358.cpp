extern "C" float func_002FD3D0(const void *curve, float u);
extern const char D_00583810[];
extern const char D_00583820[];

extern "C" float func_00310358(float u, float x, float t) {
    if (t <= x)
        return func_002FD3D0(D_00583810, u) * (x - t) / (1.0f - t);
    return func_002FD3D0(D_00583820, u) * (x - t) / (0.0f - t);
}
