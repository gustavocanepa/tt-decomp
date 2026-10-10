extern "C" void func_004A68B0(int arg0, int arg1, __builtin_va_list args);

extern "C" void func_004A6500(int arg0, int arg1, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, arg1);
    func_004A68B0(arg0, arg1, args);
}
