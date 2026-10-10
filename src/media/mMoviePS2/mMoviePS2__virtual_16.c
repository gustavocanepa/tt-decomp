static inline int plzcw(int x) { int r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(x)); return r; }

extern unsigned int D_0057A944;

float mMoviePS2__virtual_16(void)
{
    unsigned int n = D_0057A944;
    int shift = (plzcw(n - 1) & 0x1F) ^ 0x1F;
    return (float)n / (float)(unsigned int)(1 << shift);
}
