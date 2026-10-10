extern "C" void func_004A6560(const char *fmt, __builtin_va_list args);

extern "C" void func_004A6448(const char *fmt, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_004A6560(fmt, args);
}
