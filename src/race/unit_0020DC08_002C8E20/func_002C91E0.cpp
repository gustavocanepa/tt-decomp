extern "C" void func_002CE2F8(void *, void *);
extern "C" void DynamicsConductor__structor_1(void *, int);
extern "C" void func_00320900(void *, int);
extern "C" void func_003EB6A8(void *, int);
extern "C" void free(int) throw();
extern "C" void func_0050E1A8(void *) throw();
extern char D_005C8458[];
extern char D_005C8950[];
extern char D_005C92A0[];
extern "C" void func_002C91E0(char *self, int flags) {
    *(int *)(self + 0x64) = (int)D_005C8458;
    free(*(int *)(self + 0x327A0));
    {
        char *p = self + 0x32800;
        *(int *)p = (int)D_005C8950;
        func_00320900(p, 0);
    }
    func_003EB6A8(self + 0x32690, 2);
    {
        char *p = self + 0xE4C0;
        *(int *)(p + 0x241CC) = (int)D_005C92A0;
        DynamicsConductor__structor_1(p, 0);
    }
    func_002CE2F8(self, 0);
    if (flags & 1) return func_0050E1A8(self);
}
