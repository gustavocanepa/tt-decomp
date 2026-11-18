struct V3 {
    float x, y, z;
};

struct Angle {
    float v;
};

extern "C" float func_004EE530(float x);

static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float clampf(const float &v, float lo, float hi) { return minf(maxf(v, lo), hi); }

extern "C" Angle *func_003E7978(Angle *out, const V3 *a, const V3 *b) {
    float bx = b->x, ax = a->x, by = b->y, ay = a->y, bz = b->z, az = a->z;
    float d = ax * bx + ay * by + az * bz;
    out->v = 0x1.921fb4p0f - func_004EE530(clampf(d, -1.0f, 1.0f));
    return out;
}
