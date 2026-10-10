extern "C" char D_005A07B0[];

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A59F0(void *arg);
extern "C" int func_004DB6D8(void *a0, void *a1, void *a2);
extern "C" void func_004CBA28(void *a0, int *a1);
extern "C" void func_004A4DD8(void *lock);

extern "C" int func_004CB8F8(void *arg0, void *arg1, void *arg2) {
    int local;
    int sp4;

    func_004A4D68(D_005A07B0);
    while (func_004DB6D8(arg0, arg1, arg2) != 0) {
        func_004A59F0(&local);
    }
    func_004CBA28(&local, &sp4);
    func_004A4DD8(D_005A07B0);
    return sp4;
}
