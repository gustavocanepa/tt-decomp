/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001C0228(void *, int) throw();
extern "C" void func_001C0280(void *, void *) throw();
extern "C" void func_001C0998(void *, int *);
extern "C" void func_001C09F0(void *, unsigned int);
extern "C" void func_001C0AC0(void *, int, int *);
extern "C" void func_002A75A8(void *, int);
extern "C" void func_002A7590(void *, void *);
extern "C" void MFunctionEvent__global_0082AFC0(void *unused, void *src, int n, int *p) {
    void *handle[4];
    int value[4];
    if (n > 0) {
        int i = 1;
        func_001C0280(handle, src);
        func_002A7590(value, p);
        func_001C0998(handle[0], value);
        func_001C09F0(handle[0], n - 1);
        if (i < n) {
            ++p;
            do {
                func_001C0AC0(handle[0], i - 1, p);
                ++i;
                ++p;
            } while (i < n);
        }
        func_002A75A8(value, 2);
        func_001C0228(handle, 2);
    }
}
