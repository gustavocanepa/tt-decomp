typedef struct { int w[15]; } Copy60;

extern "C" {
extern char D_00776EC0[];
extern char D_00777200[];
void func_004A4D68(int a0);
void func_004A4DD8(int a0);
}

extern "C" void func_004BF890(int arg0, Copy60 *arg1) {
    char *s0 = D_00777200 + arg0 * 0x6C;
    func_004A4D68((int)D_00776EC0);
    *arg1 = *(Copy60 *)(s0 + 4);
    func_004A4DD8((int)D_00776EC0);
}
