/* compiler: ee-gcc2.96-nsa-g */
/* __ieee754_sqrtf from newlib 1.9.0 libm/math/ef_sqrt.c (fdlibm), see THIRD_PARTY.md. */
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef union { float value; __int32_t word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#define FLT_UWORD_IS_FINITE(x) ((x)<0x7f800000L)
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define FLT_UWORD_IS_SUBNORMAL(x) 0

static const float	one	= 1.0, tiny=1.0e-30;

float func_004F02E0(float x)
{
	float z;
	__int32_t 	sign = (__int32_t)0x80000000; 
	__uint32_t r,hx;
	__int32_t ix,s,q,m,t,i;

	GET_FLOAT_WORD(ix,x);
	hx = ix&0x7fffffff;

    
    
	if(FLT_UWORD_IS_ZERO(hx)) return x;
	if(ix<0) return (x-x)/(x-x);		

    
	m = (ix>>23);
	if(FLT_UWORD_IS_SUBNORMAL(hx)) {		
	    for(i=0;(ix&0x00800000L)==0;i++) ix<<=1;
	    m -= i-1;
	}
	m -= 127;	
	ix = (ix&0x007fffffL)|0x00800000L;
	if(m&1)	
	    ix += ix;
	m >>= 1;	

    
	ix += ix;
	q = s = 0;		
	r = 0x01000000L;		

	while(r!=0) {
	    t = s+r; 
	    if(t<=ix) { 
		s    = t+r; 
		ix  -= t; 
		q   += r; 
	    } 
	    ix += ix;
	    r>>=1;
	}

    
	if(ix!=0) {
	    z = one-tiny; 
	    if (z>=one) {
	        z = one+tiny;
		if (z>one)
		    q += 2;
		else
		    q += (q&1);
	    }
	}
	ix = (q>>1)+0x3f000000L;
	ix += (m <<23);
	SET_FLOAT_WORD(z,ix);
	return z;
}
