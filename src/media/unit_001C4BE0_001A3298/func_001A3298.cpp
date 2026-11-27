/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001A3298(char *p, int a, int b)
{
    if (a == b) return;
    int ma = 1 << (a & 7);
    int mb = 1 << (b & 7);
    int va = p[a >> 3] & ma;
    int vb = (p[b >> 3] & mb) != 0;
    if (va)
        p[b >> 3] |= mb;
    else
        p[b >> 3] &= ~mb;
    if (vb)
        p[a >> 3] |= ma;
    else
        p[a >> 3] &= ~ma;
}
