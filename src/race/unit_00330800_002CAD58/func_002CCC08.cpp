/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rd { s32 p0; s32 size; s32 p8; s32 pC; };
struct Obj { s32 u0; s32 u4; s32 u8; };

extern char D_005F2760[];
extern "C" bool func_00423E80(void *);
extern "C" void func_004242C0(void *, void *);
extern "C" void func_00424408(void *, void *, char *);

extern "C" bool func_002CCC08(Obj *arg0) {
    Rd r;
    s32 d = arg0->u8 - arg0->u0;
    func_00424408(&r, arg0, D_005F2760);
    if (r.size < 0) {
        arg0->u8 = arg0->u0 + d;
        return true;
    }
    func_004242C0(&r, arg0);
    bool res = !func_00423E80(arg0);
    arg0->u8 = arg0->u0 + d;
    return res;
}
