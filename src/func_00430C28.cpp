/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00438148(void *, int, int, float, float *, float *, float *, int *, int *);
extern "C" int func_00438650(void *, int, int, float, float *, float *, float *, int *, int *);
extern "C" float func_004A5B78(float, float);
static inline float root(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_00430C28(void *obj, int key, int idx, float *ox, float *oy, float *oz, float t) {
    float x, y, z;
    float xx, yy, zz;
    float dx, dy;
    if (key != 4) func_00438148(obj, key, idx, t, &x, &y, &z, 0, 0);
    else func_00438650(obj, key, idx, t, &x, &y, &z, 0, 0);
    for (int i = 0; i < 10; i++) {
        t += 0.5f;
        if (key != 4) func_00438148(obj, key, idx, t, &xx, &yy, &zz, 0, 0);
        else func_00438650(obj, key, idx, t, &xx, &yy, &zz, 0, 0);
        dx = xx - x;
        dy = yy - y;
        if (root(dx * dx + dy * dy) >= 0.2f) break;
    }
    *ox = x;
    *oy = y;
    *oz = z;
    return func_004A5B78(-dx, dy);
}
