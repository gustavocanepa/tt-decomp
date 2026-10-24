/* compiler: ee-gcc2.96-nsa-g */
/* modf from newlib 1.9.0 libm/common/s_modf.c (fdlibm, Sun Microsystems), see THIRD_PARTY.md. */
typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct { __uint32_t lsw; __uint32_t msw; } parts;
} ieee_double_shape_type;

#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

static const double one = 1.0;


extern "C" double func_004EDD60(double x, double *iptr)
{
	__int32_t i0,i1,j0;
	__uint32_t i;
	EXTRACT_WORDS(i0,i1,x);
	j0 = ((i0>>20)&0x7ff)-0x3ff;
	if(j0<20) {
	    if(j0<0) {
	        INSERT_WORDS(*iptr,i0&0x80000000,0);
		return x;
	    } else {
		i = (0x000fffff)>>j0;
		if(((i0&i)|i1)==0) {
		    __uint32_t high;
		    *iptr = x;
		    GET_HIGH_WORD(high,x);
		    INSERT_WORDS(x,high&0x80000000,0);
		    return x;
		} else {
		    INSERT_WORDS(*iptr,i0&(~i),0);
		    return x - *iptr;
		}
	    }
	} else if (j0>51) {
	    __uint32_t high;
	    *iptr = x*one;
	    GET_HIGH_WORD(high,x);
	    INSERT_WORDS(x,high&0x80000000,0);
	    return x;
	} else {
	    i = ((__uint32_t)(0xffffffff))>>(j0-20);
	    if((i1&i)==0) {
	        __uint32_t high;
		*iptr = x;
		GET_HIGH_WORD(high,x);
		INSERT_WORDS(x,high&0x80000000,0);
		return x;
	    } else {
	        INSERT_WORDS(*iptr,i0,i1&(~i));
		return x - *iptr;
	    }
	}
}
