extern "C" int func_003EEBE8(int);
extern "C" void func_003F0070(void *self, int a, int b, float c, int d, int e, float f);

extern "C" void func_003F0128(void *self, int unused, int b, float c, int d, int e, float f) {
    int p = *(int *)((char *)self + 4);
    if (p != 0) {
        func_003F0070(self, func_003EEBE8(p), b, c, d, e, f);
    }
}
