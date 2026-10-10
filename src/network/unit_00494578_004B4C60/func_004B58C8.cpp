extern "C" unsigned char D_00773EA2;
extern "C" float func_004B5F48(int *a, int *b, int *c);

extern "C" float func_004B58C8(int *a, int *b, int *c)
{
    if (!D_00773EA2) {
        if (a)
            *a = 0;
        if (b)
            *b = 0;
        if (c)
            *c = 0;
        return 0.0f;
    }
    return func_004B5F48(a, b, c);
}
