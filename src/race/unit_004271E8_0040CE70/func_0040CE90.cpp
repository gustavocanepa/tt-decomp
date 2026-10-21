struct Db { char p[0x1EC]; int f1E4; };
extern Db D_00585A30;
extern char D_005FBDC0[];
extern "C" long func_0040CFE0();
extern "C" int func_0040B940(void *, int, int, void *);
extern "C" const char *func_00411D78(int, int);

extern "C" const char *func_0040CE90() {
    int v;
    int key = (int)((unsigned long)func_0040CFE0() & 0xFFFFFFFFUL);
    if (func_0040B940(&D_00585A30, key, 0x27, &v) == 0)
        return D_005FBDC0;
    return func_00411D78(D_00585A30.f1E4, v);
}
