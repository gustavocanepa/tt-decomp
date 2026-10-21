/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    int f0;
    int f4;
    void *f8;
    int fC;
    int f10;
    int f14;
    char f18[1];
};
extern "C" void func_00107240(Obj *, int) throw();
extern "C" void func_00107280(Obj *) throw();
extern "C" void pgluTexReset(void *);
extern "C" void pgluTexImage(void *, int, unsigned int, unsigned int, int);
extern "C" void func_00468F10(void *, int, int);
extern "C" void func_00468FE0(void *, unsigned int, int);
extern "C" void func_00469158(void *, int, int, int);
extern "C" int func_00469230(unsigned int, int, int, int *);
extern "C" unsigned char func_0046E2B8(void);
extern "C" void func_0046FB08(int);
extern "C" void func_00472628(void);
extern "C" void func_00472C50(int, int, int, int, int, int, int, int);
extern "C" void func_00472DC8(int, int, int, int, int, int, int, int);

extern "C" void func_00107368(Obj *obj, unsigned int psm, int w, int h, int extra) {
    int outw;
    int r = func_00469230(psm, w, h, &outw);
    func_00107280(obj);
    func_00107240(obj, r);
    if (func_0046E2B8()) {
        func_00472C50(obj->f0, psm, outw, 0, 0, w, h, extra);
        func_0046FB08(1);
        func_00472628();
    } else {
        func_00472DC8(obj->f0, psm, outw, 0, 0, w, h, extra);
    }
    void *sub = obj->f18;
    obj->fC = 1;
    obj->f8 = sub;
    pgluTexReset(sub);
    pgluTexImage(obj->f8, 0, obj->f0, psm, outw);
    func_00468F10(obj->f8, w, h);
    func_00469158(obj->f8, 0, 0, w - 1);
    func_00469158(obj->f8, 1, 0, h - 1);
    func_00468FE0(obj->f8, 4, 1);
    func_00468FE0(obj->f8, 5, 1);
}
