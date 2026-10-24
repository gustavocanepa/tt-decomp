/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry3C2A58 { s16 delta; s16 index; void *fn; };
struct Obj3C2A58 { char p0[4]; char *vt; };

extern "C" void func_004242C0(void *arg0, void *arg1);
extern "C" s32 GT4Model__BinStreamReader__read8u(void *arg0);
extern "C" void *func_00393570(void *arg0) throw();
extern "C" void *func_003935B8(void *arg0) throw();
extern "C" void func_004243E0(void *arg0, void *arg1);

extern "C" void func_00393900(void *arg0, void *arg1) {
    char sp[0x10];
    void *a3;
    s32 r;
    s32 one;
    func_004242C0(sp, arg1);
    GT4Model__BinStreamReader__read8u(arg1);
    while ((r=GT4Model__BinStreamReader__read8u(arg1)) != 0) {
        {
            s32 t = r - 1;
            a3 = 0;
            switch(t) {
            case 0: a3=func_00393570(arg0); break;
            case 1: a3=func_003935B8(arg0); break;
            }
            if (a3 != 0) {
                VEntry3C2A58 *e = (VEntry3C2A58 *)(((Obj3C2A58 *)a3)->vt + 0x30);
                ((void (*)(void *, void *, void *))e->fn)((char *)a3 + e->delta, arg1, arg0);
            }
        }
    }
    func_004243E0(sp, arg1);
}
