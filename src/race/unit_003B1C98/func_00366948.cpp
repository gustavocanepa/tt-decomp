/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0036F578(void *) throw();
extern "C" int func_00366AB8(void *, int, int, int, float, void *, int, int);
extern "C" int func_00366948(char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, float f) {
    char *p = arg0 + 0xD58;
    func_0036F578(p);
    int r = func_00366AB8(arg0, arg1, arg2, arg3, f, p, arg4, arg5);
    if (r != 0) {
        *(int *)(arg0 + 0xD54) += 1;
    }
    return r;
}
