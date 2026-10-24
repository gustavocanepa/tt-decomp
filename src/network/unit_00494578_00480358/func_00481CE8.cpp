/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    void *m0;
    int m4, m8, mC, m10, m14, m18;
};
extern "C" void free(void *) throw();

extern "C" void func_00481CE8(O *o) {
    void *old = o->m0;
    o->m4 = 0;
    o->m8 = 0;
    o->mC = 0;
    o->m14 = 0;
    o->m18 = 0;
    o->m0 = 0;
    char *p8 = (char *)o + 12;
    char *pC = (char *)o + 0x10;
    int off = 0x20;
    int n = 1;
    do {
        char *x = p8 + off;
        char *y = pC + off;
        n--;
        *(int *)x = 0;
        off += 0x41C;
        *(int *)y = 0;
    } while (n >= 0);
    free(old);
}
