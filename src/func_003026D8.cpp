extern "C" int func_00301F08(void *arg0);
extern "C" void func_00301F88(void *arg0, int arg1, int arg2) throw();

extern "C" void func_003026D8(void *arg0, int arg1) {
    if (func_00301F08(arg0) == 0) {
        return;
    }
    if ((unsigned int)(arg1 - 1) < 2) {
        return func_00301F88(arg0, 5, -1);
    }
    if ((unsigned int)(arg1 - 5) < 2) {
        return func_00301F88(arg0, 8, -1);
    }
    if (arg1 < 8) {
        return func_00301F88(arg0, 4, -1);
    }
    if (arg1 < 0xB) {
        return func_00301F88(arg0, 5, 0xD2);
    }
    if (arg1 == 0xB || arg1 == 0xF) {
        return func_00301F88(arg0, 4, 0xD2);
    }
    return func_00301F88(arg0, 8, 0xD2);
}
