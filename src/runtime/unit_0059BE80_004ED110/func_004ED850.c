/* compiler: ee-gcc2.96-nsa-g */
/* cos from newlib 1.9.0 libm: s_cos.c (fdlibm, Sun Microsystems), see THIRD_PARTY.md. */
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


int func_004F1AB8(double,double*);
double func_004F31B8(double,double,int);
double func_004F2390(double,double);

	double func_004ED850(double x)
{
	double y[2],z=0.0;
	__int32_t n,ix;
	GET_HIGH_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return func_004F2390(x,z);
	else if (ix>=0x7ff00000) return x-x;
	else {
	    n = func_004F1AB8(x,y);
	    switch(n&3) {
		case 0: return  func_004F2390(y[0],y[1]);
		case 1: return -func_004F31B8(y[0],y[1],1);
		case 2: return -func_004F2390(y[0],y[1]);
		default:
		        return  func_004F31B8(y[0],y[1],1);
	    }
	}
}
