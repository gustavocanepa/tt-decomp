struct Obj;
extern "C" float func_002E5E40(Obj *, float);
extern "C" float func_002E5EA0(Obj *, float);
extern "C" float func_002E5ED0(Obj *, float);
extern "C" float func_002E5F00(Obj *, float);
extern "C" float func_002E5F30(Obj *, float);
extern "C" float func_002E5F60(Obj *, float);
extern "C" void func_0046E150(void);
extern "C" void func_0046E1B0(void);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_004755EC(float, float, float);
extern "C" void func_00475730(float);
extern "C" void func_00475758(float);
extern "C" void func_00475780(float);
extern "C" void func_00475850(void *, void *);

extern "C" void func_003A8510(int *flags, float *pos, Obj *o, float t)
{
    float v[4];
    func_0046E150();
    func_00473050();
    func_004751FC();
    if ((*flags >> 2) & 1) func_00475780(func_002E5F30(o, t) * 0x1.ca5dc0p+5f);
    if (*flags & 1) func_00475730(-func_002E5F00(o, t) * 0x1.ca5dc0p+5f);
    if ((*flags >> 1) & 1) func_00475758(-func_002E5F60(o, t) * 0x1.ca5dc0p+5f);
    float a = -func_002E5E40(o, t);
    float b = -func_002E5EA0(o, t);
    func_004755EC(a, b, -func_002E5ED0(o, t));
    float x0 = pos[0];
    int o1 = 4, o2 = 8;
    float *py = (float *)((char *)pos + o1);
    float *pz = (float *)((char *)pos + o2);
    float *vy = (float *)((char *)v + o1);
    float *vz = (float *)((char *)v + o2);
    v[0] = x0;
    *vy = *py;
    *vz = *pz;
    v[3] = 1.0f;
    func_00475850(v, v);
    pos[0] = v[0];
    *py = *vy;
    *pz = *vz;
    func_004730A8();
    func_0046E1B0();
}
