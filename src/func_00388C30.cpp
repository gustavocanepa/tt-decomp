/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline int count() { return 2; }
extern "C" void func_00388C30(int *p) {
    int *slots = p + 1;
    for (int i = 0; i < 6; ++i) {
        int *q = slots;
        for (int n = 0; n < count(); n++) {
            *q = 0;
            ++q;
        }
        p[i * 3] = 0;
        slots += 3;
    }
}
