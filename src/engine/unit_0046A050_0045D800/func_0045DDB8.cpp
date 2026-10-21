extern "C" int func_004A8368(const char *);
extern "C" void func_0045F5C8(int, float *, float *, const char *);
extern "C" int func_004B5138(const char *);
extern "C" void func_0045DD30(int, const char *, int, const char *);
extern char D_00603D20[];

extern "C" int func_0045DDB8(int a, int b, int c, const char *s, float limit) {
    float o[2];
    const char *lit = D_00603D20;
    if (func_004A8368(s) + 3 >= c) return 0;
    func_0045F5C8(a, &o[0], &o[1], s);
    if (o[0] < limit) return 0;
    float r = limit / o[0];
    int k = (int)((float)func_004B5138(s) * r);
    while (k >= 0) {
        int cur = k;
        k--;
        func_0045DD30(b, s, cur, lit);
        func_0045F5C8(a, &o[0], &o[1], (const char *)b);
        if (o[0] < limit) break;
    }
    return 1;
}
