/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0019AB38(void *) throw();
extern "C" int func_00197D80(void *, void *, const char *);
extern "C" int func_001A19E8(void *, void *, int);
extern "C" char D_005E6F90[], D_005AC3A8[];
struct Obj {
    char *vt;
    char pad[0x4c];
    Obj(void *p) { func_00197D80(this, p, D_005E6F90); }
    ~Obj() { vt = D_005AC3A8; }
};
extern "C" int func_001A1978(void *arg0, int arg1) {
    char buf[0x40];
    func_0019AB38(buf);
    Obj obj(buf);
    func_001A19E8(&obj, arg0, arg1);
}
