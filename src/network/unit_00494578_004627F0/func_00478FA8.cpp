/* compiler: ee-gcc2.96-no-strict-aliasing */
struct R {
    char pad0[0x1D8];
    unsigned long l1D8;
    unsigned long l1E0;
    unsigned long l1E8;
};
extern char D_0058C518[];
extern char D_0058C528[];
extern char D_0058C538[];
extern "C" int func_00478F70(int, long, char *, void *) throw();

extern "C" int func_00478FA8(R *o, int b) {
    int v0 = 0;
    int a3 = b;
    unsigned long v1 = o->l1D8;
    unsigned long s1 = v1 & o->l1E8;
    unsigned long a0 = (s1 >> 32);
    a0 &= 0x3FF;
    if (s1 == 0) return v0;
    o->l1D8 = v1 & ~s1;
    o->l1E0 = o->l1E0 | s1;
    if (a0 != 0) {
        a3 = func_00478F70(b, a0, D_0058C518, (char *)o + 0x120);
    }
    a0 = s1 & 0x1FFF;
    if (a0 != 0) {
        a3 = func_00478F70(a3, a0, D_0058C528, (char *)o + 0x170);
    }
    a0 = (s1 >> 16);
    a0 &= 0x1FFF;
    if (a0 != 0) {
        a3 = func_00478F70(a3, a0, D_0058C538, (char *)o + 0x170);
    }
    v0 = (a3 - b) >> 4;
    return v0;
}
