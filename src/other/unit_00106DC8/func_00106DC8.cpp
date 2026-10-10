typedef int s32;

extern char D_005794F0[];
extern char D_005DE6A0[];

extern "C" void func_0046DE58(s32 arg0);
extern "C" void func_001058F0(void *arg0, s32 arg1);
extern "C" void func_0046EE88(void *arg0);

extern "C" void func_00106DC8(void) {
    func_0046DE58(2);
    func_001058F0(D_005794F0, 1);
    func_0046EE88(D_005DE6A0);
}
