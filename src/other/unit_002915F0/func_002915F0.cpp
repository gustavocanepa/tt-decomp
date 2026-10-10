typedef void (*FuncPtr)(int);

extern "C" FuncPtr func_002908F8();

extern "C" int func_002915F0(int arg0, int arg1, int arg2)
{
    FuncPtr fn = func_002908F8();
    if (fn != 0) {
        fn(arg2);
        return 1;
    }
    return (int)fn;
}
