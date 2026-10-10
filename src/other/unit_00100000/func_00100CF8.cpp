typedef int s32;

extern char D_00578E28[];
extern char D_00578E68[];

extern "C" void func_00100738(s32 arg0);
extern "C" void func_00100798(void *buf);

extern "C" void func_00100CF8(void) {
    func_00100738((s32)D_00578E28);
    func_00100798(D_00578E68);
}
