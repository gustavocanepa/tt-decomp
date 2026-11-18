extern "C" int func_0040B710(void *self, char *buf, char *ext);
extern "C" int func_0040B800(void *self, int i);
extern "C" void func_00411830(void *o);
extern "C" int func_004118C0(void *o, char *buf);
extern "C" int func_00411910(void *o, char *buf, int a, int b);
extern "C" int func_004A4690(int a, int b);
extern "C" void func_004F7A30(char *d, char *s);
extern "C" char *func_004F7B74(char *d, char *s);
extern "C" void *exception__structor_0(int n);
extern char *D_00585940[];
extern char *D_00585A20[];
extern char D_005FBCF0[];

extern "C" void func_0040B460(char *self, int idx) {
    char buf[0x100];
    char *name = self + 8;
    func_004F7B74(buf, name);
    func_004F7A30(buf, D_00585940[idx]);
    int off = idx * 4;
    off += 0x80;
    void **slot = (void **)(name + off);
    void *o = exception__structor_0(0xC);
    func_00411830(o);
    *slot = o;
    if (func_0040B800(self, idx) != 0) {
        int a = func_0040B710(self, buf, D_005FBCF0);
        int b = func_004A4690(0x40, a);
        func_004F7A30(buf, D_00585A20[*(int *)(self + 4)]);
        func_004F7A30(buf, D_005FBCF0);
        func_00411910(*slot, buf, b, a);
        return;
    }
    func_004F7A30(buf, D_005FBCF0);
    func_004118C0(*slot, buf);
}
