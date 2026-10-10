extern "C" void func_004B3220(const char *fmt, __builtin_va_list args);

extern "C" void func_004AE960(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_004B3220(fmt, args);
}
