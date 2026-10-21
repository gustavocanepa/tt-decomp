/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad[0x4C];
    int handle, count, pending, f58, f5C, f60;
};
extern "C" int func_005038D8(void);
extern "C" int func_004CB4B8(int, int, int *, int *, int *);
extern "C" void func_004B7680(Obj *, int, int, int, int, int) throw();
extern "C" void func_004B7760(Obj *p) {
    int value, a, b;
    int *pa = 0;
    int *pb = 0;
    int enabled = func_005038D8();
    int *pv = &value;
    a = p->f5C;
    b = p->f60;
    if (p->pending) {
        p->pending = 0;
        pa = &a;
        pb = &b;
    }
    if (enabled) __asm__ volatile("ei");
    int flag = 0;
    int status;
    int again;
    do {
        status = func_004CB4B8(p->handle, p->count, pv, pa, pb);
        if (status < -10) status = -11;
        again = 0;
        switch (status) {
        case 0:
            if (pa) {
                again = 1;
                pa = 0;
                pb = 0;
            }
            break;
        case -1:
            again = 1;
            pa = &a;
            pb = &b;
            flag = 1;
            break;
        case -11:
            value = 0;
            a = 0;
            b = 0;
            break;
        case -2:
            a = 0;
            flag = 1;
            b = 0;
            break;
        }
    } while (again);
    func_004B7680(p, status, value, a, b, flag);
}
