struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };
struct Obj;
struct Tuning {
    char pad[0x10];
    float f10, f14, f18, f1C, f20, f24, f28, f2C, f30;
};
extern Tuning D_005845D0;
extern "C" void func_00392200(Obj *o, Vec3 *p, Vec3 *v, Vec4 *c, int kind, float mass, float factor, float value) throw();
extern "C" Obj *func_00393570(Obj *m);
extern "C" float pglmRandom(void);
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();

static inline float root(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline Obj *next_particle(Obj *mgr) { return func_00393570(mgr); }
extern "C" void func_00393350(Obj *mgr, Vec3 *pos, Vec3 *vel, Vec4 *color, int count) {
    Vec3 v;
    int i = 0;
    float len = root(vel->x * vel->x + vel->z * vel->z);
    if (count > 0) {
        do {
            void *work = next_particle(mgr);
            Obj *p = (Obj *)work;
            if (!p)
                break;
            i++;
            work = &D_005845D0;
            Tuning *t = (Tuning *)work;
            float a = (pglmRandom() - 0.5f) * 0x1.1df468p-6f * t->f10;
            float sp = pglmRandom() * (t->f18 - t->f14) + t->f14;
            float s = func_004A5D18(a) * sp;
            float c = func_004A5C50(a) * sp;
            v.x = c * vel->x - s * vel->z;
            float r3 = pglmRandom();
            float r4 = pglmRandom();
            float q = (r3 + r4) * 0.5f;
            v.y = vel->y + (q - 0.5f) * len * t->f1C;
            v.z = s * vel->x + c * vel->z;
            float sz = pglmRandom() * (t->f24 - t->f20) + t->f20;
            float m = sz * sz * sz * t->f28;
            float w = pglmRandom() * (t->f30 - t->f2C) + t->f2C;
            func_00392200(p, pos, &v, color, 0xFF229EFF, m, sz, w);
        } while (i < count);
    }
}
