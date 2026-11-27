struct Obj {
    char pad0[0x17C];
    int n174;
};

struct Text5 { char c[5]; };

extern void *D_00586EF8;
extern "C" const Text5 D_005E0FD8;
extern "C" const char D_005E0FE0[];
extern "C" void func_0045F468(void *mgr, char *buf, int size, int value, const char *fmt);

extern "C" void func_00131FD8(Obj *o, int size, char *buf) {
    int r = o->n174;
    if (r <= 0) {
        *(Text5 *)buf = D_005E0FD8;
        return;
    }
    func_0045F468(D_00586EF8, buf, size, r, D_005E0FE0);
}
