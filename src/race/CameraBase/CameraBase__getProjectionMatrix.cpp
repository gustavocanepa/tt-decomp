struct Obj {
    virtual void v0();
    virtual void update(float t);
};

extern "C" void func_00473050(void);
extern "C" void func_004751FC(void);
extern "C" void func_004752F8(void *x);
extern "C" void func_004730A8(void);

extern "C" void CameraBase__getProjectionMatrix(Obj *o, void *x, float t) {
    func_00473050();
    func_004751FC();
    o->update(t);
    func_004752F8(x);
    func_004730A8();
}
