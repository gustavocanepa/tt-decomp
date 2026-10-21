struct B { int w[11]; };
extern B D_00585720;
extern B D_00585750;
extern B D_00585780;
extern B D_005857B0;
extern B D_005FA990, D_005FA9C0;
static inline void ctor(B *const self, const B *const s) { *self = *s; }
extern "C" void func_00400448(int init, int prio) {
    if (prio == 0xFFFF && init == 1) ctor(&D_00585720, &D_005FA990);
    if (prio == 0xFFFF && init == 1) ctor(&D_00585750, &D_005FA9C0);
    if (prio == 0xFFFF && init == 1) ctor(&D_00585780, &D_005FA990);
    if (prio == 0xFFFF && init == 1) ctor(&D_005857B0, &D_005FA9C0);
}
