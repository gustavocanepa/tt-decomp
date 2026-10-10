extern "C" void func_004A6978(int arg0, int arg1, __builtin_va_list args);

extern "C" void func_004A6918(int arg0, int arg1, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, arg1);
    func_004A6978(arg0, arg1, args);
}
