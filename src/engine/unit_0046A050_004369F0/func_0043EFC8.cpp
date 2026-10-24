struct S;
struct Val;

extern "C" float func_0043E0B0(S *arg0);
extern "C" void func_0043D810(void *arg0, int arg1);
extern "C" void func_0043F580(Val *self);

extern "C" void func_0043EFC8(Val *arg0, int arg1) {
    int a = (int)func_0043E0B0((S *)arg0);
    int b = (int)func_0043E0B0((S *)arg1);
    if (b != 0) {
        return func_0043D810(arg0, a % b);
    }
    func_0043F580(arg0);
}
