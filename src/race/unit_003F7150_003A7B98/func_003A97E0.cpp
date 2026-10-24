extern "C" void func_0034B590(int, float *, int *, float *);
extern "C" void func_0046E150(void);
extern "C" void func_0046E1B0(void);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_004755EC(float, float, float);
extern "C" void func_004757FC(void);
extern "C" void func_00475850(void *, void *);

extern "C" float func_003A97E0(int a, float *p, int *q)
{
    float v[4];
    float r[4];
    float pl[4];
    float res = 0.0f;
    int o1 = 4, o2 = 8;
    float *vy = (float *)((char *)v + o1);
    float *vz = (float *)((char *)v + o2);
    v[0] = res;
    *vy = res;
    *vz = res;
    v[3] = 1.0f;
    func_0046E150();
    func_00473050();
    func_004751FC();
    float t1 = *(float *)((char *)p + o1) + 3.0f;
    float t2 = *(float *)((char *)p + o2);
    float t0 = p[0];
    func_004755EC(-t0, -t1, -t2);
    func_004757FC();
    func_00475850(v, v);
    r[0] = v[0];
    r[1] = *vy;
    r[2] = *vz;
    func_0034B590(a, r, q, pl);
    if (*q >= 0 && pl[1] != 0.0f)
        res = -(r[0] * pl[0] + r[2] * pl[2] + pl[3]) / pl[1];
    func_004730A8();
    func_0046E1B0();
    return res;
}
