extern "C" int func_0026AA90(int arg1);
extern "C" void func_00202758(int arg0, int *arg1);

extern "C" int func_0026C458(int arg0, int arg1) {
    int local1;
    int local2;
    int v0 = func_0026AA90(arg1);
    if (v0 != 0) {
        local1 = v0;
        func_00202758(arg0, &local1);
    } else {
        local2 = 0;
        func_00202758(arg0, &local2);
    }
    return arg0;
}
