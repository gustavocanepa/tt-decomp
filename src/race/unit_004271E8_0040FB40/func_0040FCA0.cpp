/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;
struct Db { char p[0x1E8]; int f1E0; int f1E4; };
extern Db D_00585A30;
extern "C" int func_0040B800(void *, int);
extern "C" void func_00411D78(int, int);

extern "C" void func_0040FCA0(int arg0) {
    if (func_0040B800(&D_00585A30, 0x2A) != 0) {
        func_00411D78(D_00585A30.f1E4, arg0);
        return;
    }
    func_00411D78(D_00585A30.f1E0, arg0);
    return;
}
