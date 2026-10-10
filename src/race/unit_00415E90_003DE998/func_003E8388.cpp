typedef int u128 __attribute__((mode(TI)));

union Quat {
    float v[4];
    u128 q;
};

extern "C" void func_0044E020(Quat *q, float angle);
extern "C" Quat func_003E6350(const Quat *q, const void *axis);

static inline void fromAngle(Quat *q, const float &a) { func_0044E020(q, a); }

extern "C" void func_003E8388(Quat *out, int unused, const void *axis, const float *angle, Quat *rot) {
    Quat q;
    float a = *angle;
    fromAngle(&q, a);
    const Quat &r = func_003E6350(&q, axis);
    out->q = r.q;
    if (rot)
        rot->q = q.q;
}
