/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libgcc2.c __cmpdi2 with 32-bit words (DWtype is a 64-bit long long). */
typedef int SItype;
typedef unsigned int USItype;
typedef long long DItype;
struct DIstruct { SItype low, high; };
typedef union { struct DIstruct s; DItype ll; } DIunion;

int func_00508E20(DItype a, DItype b) {
    DIunion au, bu;

    au.ll = a, bu.ll = b;

    if (au.s.high < bu.s.high)
        return 0;
    else if (au.s.high > bu.s.high)
        return 2;
    if ((USItype) au.s.low < (USItype) bu.s.low)
        return 0;
    else if ((USItype) au.s.low > (USItype) bu.s.low)
        return 2;
    return 1;
}
