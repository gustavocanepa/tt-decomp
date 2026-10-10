extern "C" void func_004B3200(const char *fmt, __builtin_va_list args);

extern "C" void func_004AE900(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_004B3200(fmt, args);
}
