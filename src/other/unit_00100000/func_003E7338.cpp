extern "C" int func_003E72F0(int a, int b);

extern "C" int func_003E7338(int n, int *v)
{
    if (n <= 0)
        return 0;
    int r = v[0];
    for (int i = 1; i < n; i++)
        r = func_003E72F0(r, v[i]);
    return r;
}
