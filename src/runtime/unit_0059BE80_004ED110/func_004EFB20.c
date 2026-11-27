/* compiler: ee-gcc2.96-nsa-g */
/* __ieee754_asinf from newlib 1.9.0 libm/math/ef_asin.c (fdlibm, Sun Microsystems), see THIRD_PARTY.md. */
typedef int __int32_t;

typedef union { float value; __int32_t word; } ieee_float_shape_type;

#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

extern float func_004F40B0(float);	/* fabsf */
extern float func_004F02E0(float);	/* __ieee754_sqrtf */

static const float 
one =  1.0000000000e+00,
huge =  1.000e+30,
pio2_hi =  1.5707962513e+00,
pio2_lo =  7.5497894159e-08,
pio4_hi =  7.8539818525e-01,
pS0 =  1.6666667163e-01,
pS1 = -3.2556581497e-01,
pS2 =  2.0121252537e-01,
pS3 = -4.0055535734e-02,
pS4 =  7.9153501429e-04,
pS5 =  3.4793309169e-05,
qS1 = -2.4033949375e+00,
qS2 =  2.0209457874e+00,
qS3 = -6.8828397989e-01,
qS4 =  7.7038154006e-02;

float func_004EFB20(float x)
{
	float t,w,p,q,c,r,s;
	__int32_t hx,ix;
	GET_FLOAT_WORD(hx,x);
	ix = hx&0x7fffffff;
	if(ix==0x3f800000) {
	    return x*pio2_hi+x*pio2_lo;
	} else if(ix> 0x3f800000) {
	    return (x-x)/(x-x);
	} else if (ix<0x3f000000) {
	    if(ix<0x32000000) {
		if(huge+x>one) return x;
          } else {
		t = x*x;
		p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
		q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
		w = p/q;
		return x+x*w;
          }
	}
	w = one-func_004F40B0(x);
	t = w*(float)0.5;
	p = t*(pS0+t*(pS1+t*(pS2+t*(pS3+t*(pS4+t*pS5)))));
	q = one+t*(qS1+t*(qS2+t*(qS3+t*qS4)));
	s = func_004F02E0(t);
	if(ix>=0x3F79999A) {
	    w = p/q;
	    t = pio2_hi-((float)2.0*(s+s*w)-pio2_lo);
	} else {
	    __int32_t iw;
	    w  = s;
	    GET_FLOAT_WORD(iw,w);
	    SET_FLOAT_WORD(w,iw&0xfffff000);
	    c  = (t-w*w)/(s+w);
	    r  = p/q;
	    p  = (float)2.0*s*r-(pio2_lo-(float)2.0*c);
	    q  = pio4_hi-(float)2.0*w;
	    t  = pio4_hi-(p-q);
	}
	if(hx>0) return t; else return -t;
}
