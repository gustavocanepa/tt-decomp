extern "C" int func_00489720(int, int, int);
extern "C" int *func_001A89C0(int *o, int *in, int x, int a3, int t0, int mode) {
    int f = 0;
    int *p = in + 2;
    switch (mode) {
    case 1: f = 0; break;
    case 0: f = 2; break;
    case 2: f = 1; break;
    }
    if (a3) f |= 0x200;
    if (t0) f |= 0x800;
    int r = func_00489720(*p, x, f);
    int v = *p;
    o[1] = r;
    o[0] = v;
    return o;
}
