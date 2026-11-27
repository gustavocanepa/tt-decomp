extern "C" int func_0040B710(void *self, char *buf, char *ext);
extern "C" int func_0040B800(void *self, int i);
extern "C" void func_00410EB0(void *o);
extern "C" int func_00410F90(void *o, char *buf);
extern "C" int func_00411008(void *o, char *buf, int a, int b);
extern "C" int func_004A4690(int a, int b);
extern "C" void func_004F7A30(char *d, char *s);
extern "C" char *func_004F7B74(char *d, char *s);
extern "C" void *exception__structor_0(int n);
extern char *D_00585940[];
extern char *D_00585A20[];
extern char D_005FBCE8[];

extern "C" void func_0040B330(char *self, int idx) {
    char buf[0x100];
    char *name = self + 8;
    func_004F7B74(buf, name);
    func_004F7A30(buf, D_00585940[idx]);
    int off = idx * 4;
    off += 0x130;
    void **slot = (void **)(name + off);
    void *o = exception__structor_0(0x6C);
    func_00410EB0(o);
    *slot = o;
    if (func_0040B800(self, idx) != 0) {
        int a = func_0040B710(self, buf, D_005FBCE8);
        int b = func_004A4690(0x40, a);
        func_004F7A30(buf, D_00585A20[*(int *)(self + 4)]);
        func_004F7A30(buf, D_005FBCE8);
        func_00411008(*slot, buf, b, a);
        return;
    }
    func_004F7A30(buf, D_005FBCE8);
    func_00410F90(*slot, buf);
}
