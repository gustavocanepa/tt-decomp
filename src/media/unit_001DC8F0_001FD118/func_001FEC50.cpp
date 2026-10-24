/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001FFE08(void *a, int b);
extern "C" void func_004A4D68(int a);
extern "C" void func_004A4DD8(int a);
extern "C" void func_0052EC80(void *a);

extern "C" void func_001FEC50(char *arg0) {
    char *s1 = arg0 + 0x11C;
    func_001FFE08(arg0, 0);
    func_004A4D68((int)s1);
    func_0052EC80(arg0 + 0x10);
    func_004A4DD8((int)s1);
}
