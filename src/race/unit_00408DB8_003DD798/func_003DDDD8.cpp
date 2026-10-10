struct Vec3 { float x, y, z; };
extern "C" void func_004A6328(float a, float *s, float *c);
extern "C" void func_003DDD48(void *o, Vec3 *v);

extern "C" void func_003DDDD8(void *o, float *angle)
{
    float sc[4];
    Vec3 v;
    int spare[4];
    *angle -= 1.5707963f;
    Vec3 *pv = &v;
    pv->x = *angle;
    func_004A6328(pv->x, &sc[0], &sc[1]);
    float c = sc[1], sn = sc[0];
    pv->x = 0.0f;
    v.y = c;
    v.z = sn;
    func_003DDD48(o, &v);
    spare[0] = 0;
}
