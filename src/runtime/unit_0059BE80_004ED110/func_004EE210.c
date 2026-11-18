/* compiler: ee-gcc2.96-nsa-g */
/* tanh from newlib 1.9.0 libm/math/s_tanh.c (fdlibm, Sun Microsystems), see THIRD_PARTY.md. */
typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct { __uint32_t lsw; __uint32_t msw; } parts;
} ieee_double_shape_type;

#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define INSERT_WORDS(d,ix0,ix1) do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)


double func_004ED978(double);	/* fabs */
double func_004F39A0(double);	/* expm1 */

static const double one=1.0, two=2.0, tiny = 1.0e-300;

double func_004EE210(double x)
{
	double t,z;
	__int32_t jx,ix;

	GET_HIGH_WORD(jx,x);
	ix = jx&0x7fffffff;

	if(ix>=0x7ff00000) {
	    if (jx>=0) return one/x+one;
	    else       return one/x-one;
	}

	if (ix < 0x40360000) {
	    if (ix<0x3c800000)
		return x*(one+x);
	    if (ix>=0x3ff00000) {
		t = func_004F39A0(two*func_004ED978(x));
		z = one - two/(t+two);
	    } else {
	        t = func_004F39A0(-two*func_004ED978(x));
	        z= -t/(t+two);
	    }
	} else {
	    z = one - tiny;
	}
	return (jx>=0)? z: -z;
}
