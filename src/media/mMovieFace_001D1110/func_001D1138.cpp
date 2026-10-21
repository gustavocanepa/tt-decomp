/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00243440(void *);
extern "C" void func_001CB078(void *, void *);
extern "C" void func_002C0FE8(int);
extern "C" void func_002C1050(int);
extern "C" void func_001CFEC0(void *, int) throw();
extern "C" void func_001D1138(char *self) {
    int buf[4];
    func_00243440(self);
    int *out = (int *)(self + 0x1A0);
    if (*out == 0) {
        func_001CB078(buf, self + 0x178);
        if (out != buf) {
            int p = buf[0];
            if (p) func_002C0FE8(p);
            int old = *out;
            if (old) func_002C1050(old);
            *out = p;
        }
        func_001CFEC0(buf, 2);
    }
}
