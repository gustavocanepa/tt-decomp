extern "C" int func_004A8268(const char *a, const char *b);
extern "C" char D_005DCFA0[];
extern "C" char D_005E67B0[];
extern "C" char D_005E67D0[];
extern "C" char D_005E68C8[];
extern "C" char D_005E6880[];
extern "C" char D_005E68E0[];

extern "C" const char *func_0019A420(void)
{
    if (func_004A8268(D_005DCFA0, D_005E67B0) == 0)
        return D_005E68C8;
    if (func_004A8268(D_005DCFA0, D_005E67D0) == 0)
        return D_005E6880;
    return D_005E68E0;
}
