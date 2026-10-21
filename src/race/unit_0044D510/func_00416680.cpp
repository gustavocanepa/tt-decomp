/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { void *vt; char pad[0x6C]; };
extern "C" void func_00416B88(void *);
extern "C" void func_00416DD8(void *, int, float);
extern "C" void func_00416340(int, int, void *, int, int, int) throw();
extern "C" void func_00416E78(void *, int);
extern char D_005D9890[];
extern "C" void func_00416680(int a0, int a1, int a2, int a3, int t0, int t1, float f) {
    Cam c;
    func_00416B88(&c);
    func_00416DD8(&c, a2, f);
    func_00416340(a0, a1, &c, a3, t0, t1);
    c.vt = D_005D9890;
    func_00416E78(&c, 0);
}
