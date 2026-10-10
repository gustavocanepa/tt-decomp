extern "C" int func_0040FB40(int a, int b);
extern "C" int func_0040FBB0(int a);
extern "C" int func_00410AE8(int i, int b);

extern "C" int func_00410A70(int a, int b) {
    int i = func_0040FB40(a, b);
    if (i == -1) {
        i = func_0040FBB0(a);
        if (i == -1)
            return 0;
    }
    return func_00410AE8(i, b);
}
