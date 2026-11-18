extern int D_00578EF0;
extern volatile int D_00578EF4;
extern "C" void func_004A5668(int);
extern "C" void func_00101200() {
    D_00578EF4 = 1;
    func_004A5668(D_00578EF0);
}
extern "C" void func_004B6220(void);
extern "C" void func_00101930() {
    func_004B6220();
}
