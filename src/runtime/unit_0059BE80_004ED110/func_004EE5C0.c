/* compiler: ee-gcc2.96-nsa-g */
/* __ieee754_acos from newlib 1.9.0 libm: e_acos.c (fdlibm, Sun Microsystems), see THIRD_PARTY.md. */
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


#define GET_LOW_WORD(i,d) do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#define SET_LOW_WORD(d,v) do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)

double func_004F2070(double);

static const double 
one=  1.00000000000000000000e+00, 
pi =  3.14159265358979311600e+00, 
pio2_hi =  1.57079632679489655800e+00, 
pio2_lo =  6.12323399573676603587e-17, 
pS0 =  1.66666666666666657415e-01, 
pS1 = -3.25565818622400915405e-01, 
pS2 =  2.01212532134862925881e-01, 
pS3 = -4.00555345006794114027e-02, 
pS4 =  7.91534994289814532176e-04, 
pS5 =  3.47933107596021167570e-05, 
qS1 = -2.40339491173441421878e+00, 
qS2 =  2.02094576023350569471e+00, 
qS3 = -6.88283971605453293030e-01, 
qS4 =  7.70381505559019352791e-02; 
	double func_004EE5C0(double x)
{
	double z,p,q,r,w,s,c,df;
	__int32_t hx,ix;
	GET_HIGH_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix>=0x3ff00000) {	
	    __uint32_t lx;
	    GET_LOW_WORD(lx,x);
	    if(((ix-0x3ff00000)|lx)==0) {	
		if(hx>0) return 0.0;		
		else return pi+2.0*pio2_lo;	
	    }
	    return (x-x)/(x-x);		
	}
	if(ix<0x3fe00000) {	
	    if(ix<=0x3c600000) return pio2_hi+pio2_lo;
	    z = x*x;
	    p = z*(pS0+z*(pS1+z*(pS2+z*(pS3+z*(pS4+z*pS5)))));
	    q = one+z*(qS1+z*(qS2+z*(qS3+z*qS4)));
	    r = p/q;
	    return pio2_hi - (x - (pio2_lo-x*r));
	} else  if (hx<0) {		
	    z = (one+x)*0.5;
	    p = z*(pS0+z*(pS1+z*(pS2+z*(pS3+z*(pS4+z*pS5)))));
	    q = one+z*(qS1+z*(qS2+z*(qS3+z*qS4)));
	    s = func_004F2070(z);
	    r = p/q;
	    w = r*s-pio2_lo;
	    return pi - 2.0*(s+w);
	} else {			
	    z = (one-x)*0.5;
	    s = func_004F2070(z);
	    df = s;
	    SET_LOW_WORD(df,0);
	    c  = (z-df*df)/(s+df);
	    p = z*(pS0+z*(pS1+z*(pS2+z*(pS3+z*(pS4+z*pS5)))));
	    q = one+z*(qS1+z*(qS2+z*(qS3+z*qS4)));
	    r = p/q;
	    w = r*s+c;
	    return 2.0*(df+w);
	}
}
