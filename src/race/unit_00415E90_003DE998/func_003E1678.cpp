/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_004A5B78(float, float);
extern "C" float func_004EE530(float);
extern "C" void func_0044E9D8(void *, float, float, float);
struct Angle {
    float x;
    Angle(float a) : x(a) {}
    Angle(const Angle &a) : x(a.x) {}
};
struct Input { float v[16]; };
struct Output { float x,y,z,w; char q[16]; };
static inline void setq(void *q, const Angle &x, const Angle &y, const Angle &z) {
    func_0044E9D8(q, x.x, y.x, z.x);
}
extern "C" void func_003E1678(Output *o, Input *m) {
    float x = func_004A5B78(m->v[6], m->v[10]);
    float y = func_004EE530(-m->v[2]);
    float z = func_004A5B78(m->v[1], m->v[0]);
    setq(o->q, Angle(x), Angle(y), Angle(z));
    o->x = m->v[12];
    o->y = m->v[13];
    o->z = m->v[14];
}
