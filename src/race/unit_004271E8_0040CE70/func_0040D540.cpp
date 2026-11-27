extern "C" void *D_00585C1C;
extern "C" int func_0040D428(void *arg0, int arg1, char *arg2);
extern "C" void func_00411D78(void *arg0, int arg1);

extern "C" void func_0040D540(void *arg0, int arg1) {
    char buf[0x40];
    int *p;

    func_0040D428(arg0, arg1, buf);
    p = *(int **)(&D_00585C1C);
    func_00411D78(p, *(int *)(buf + 0x8));
}
