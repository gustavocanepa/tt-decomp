extern "C" float func_002158F0(int n)
{
    int p; for (p = 1; p <= 1024 && p < n; p <<= 1) ; return (float)n / p;
}
