extern "C" void func_004AE8D8(const char *fmt, __builtin_va_list args);

extern "C" void func_004AE878(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_004AE8D8(fmt, args);
}
