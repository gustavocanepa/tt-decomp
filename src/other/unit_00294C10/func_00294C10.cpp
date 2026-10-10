typedef unsigned int u32;

extern "C" void func_00294F58(void *, u32);

extern "C" void func_00294C10(void *self, u32 size) {
    u32 n = size + 1;
    u32 p = 1;
    while (p < n)
        p <<= 1;
    func_00294F58(self, p);
}
