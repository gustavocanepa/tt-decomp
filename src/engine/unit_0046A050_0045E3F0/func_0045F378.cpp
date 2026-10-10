extern "C" void func_0045FE50(void *mgr, const char *fmt, __builtin_va_list args, int one, int zero);

extern "C" void func_0045F378(void *mgr, const char *fmt, ...)
{
    __builtin_va_list args;
    __builtin_stdarg_start(args, fmt);
    func_0045FE50(mgr, fmt, args, 1, 0);
}
