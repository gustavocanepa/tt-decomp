struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, float);
};

struct CameraBase {
    VEntry *vt;
};

extern "C" void func_00473050(void);
extern "C" void func_004751FC(void);
extern "C" void func_004752F8(void *target);
extern "C" void func_004730A8(void);

extern "C" void CameraBase__getModelviewMatrix(CameraBase *self, void *target, float t)
{
    func_00473050();
    func_004751FC();
    VEntry *e = &self->vt[3];
    e->fn((char *)self + e->delta, t);
    func_004752F8(target);
    func_004730A8();
}
