/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00472A08(char *);
extern "C" int func_004729C0(char *self) {
    int n = func_00472A08(self);
    unsigned long long tag = (n | 0x8000) | (0x8000ULL << 44);
    unsigned long long *p = (unsigned long long *)(self + 0x50);
    if (n) {
        p[0] = tag;
        p[1] = 0;
    }
    return n;
}
