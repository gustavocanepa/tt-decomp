/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libgcc2.c __negdi2 with 32-bit words (DWtype is a 64-bit long long). */
typedef int SItype;
typedef unsigned int USItype;
typedef long long DItype;
struct DIstruct { SItype low, high; };
typedef union { struct DIstruct s; DItype ll; } DIunion;

DItype func_00508468(DItype u)
{
    DIunion w;
    DIunion uu;

    uu.ll = u;
    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((USItype) w.s.low > 0);
    return w.ll;
}
