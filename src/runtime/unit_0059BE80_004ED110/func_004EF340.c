/* compiler: ee-gcc2.96-nsa-g */
/* __ieee754_atan2 from newlib 1.9.0 libm/math/e_atan2.c (fdlibm, Sun Microsystems), see THIRD_PARTY.md. */
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


double func_004ED178(double);	/* atan */
double func_004ED978(double);	/* fabs */

static const double
tiny  = 1.0e-300,
zero  = 0.0,
pi_o_4  = 7.8539816339744827900E-01, 
pi_o_2  = 1.5707963267948965580E+00, 
pi      = 3.1415926535897931160E+00, 
pi_lo   = 1.2246467991473531772E-16;

double func_004EF340(double y, double x)
{  
	double z;
	__int32_t k,m,hx,hy,ix,iy;
	__uint32_t lx,ly;

	EXTRACT_WORDS(hx,lx,x);
	ix = hx&0x7fffffff;
	EXTRACT_WORDS(hy,ly,y);
	iy = hy&0x7fffffff;
	if(((ix|((lx|-lx)>>31))>0x7ff00000)||
	   ((iy|((ly|-ly)>>31))>0x7ff00000))	
	   return x+y;
	if((hx-0x3ff00000|lx)==0) return func_004ED178(y);   
	m = ((hy>>31)&1)|((hx>>30)&2);	

    
	if((iy|ly)==0) {
	    switch(m) {
		case 0: 
		case 1: return y; 	
		case 2: return  pi+tiny;
		case 3: return -pi-tiny;
	    }
	}
    
	if((ix|lx)==0) return (hy<0)?  -pi_o_2-tiny: pi_o_2+tiny;
	    
    
	if(ix==0x7ff00000) {
	    if(iy==0x7ff00000) {
		switch(m) {
		    case 0: return  pi_o_4+tiny;
		    case 1: return -pi_o_4-tiny;
		    case 2: return  3.0*pi_o_4+tiny;
		    case 3: return -3.0*pi_o_4-tiny;
		}
	    } else {
		switch(m) {
		    case 0: return  zero  ;	
		    case 1: return -zero  ;	
		    case 2: return  pi+tiny  ;	
		    case 3: return -pi-tiny  ;	
		}
	    }
	}
    
	if(iy==0x7ff00000) return (hy<0)? -pi_o_2-tiny: pi_o_2+tiny;

    
	k = (iy-ix)>>20;
	if(k > 60) z=pi_o_2+0.5*pi_lo; 	
	else if(hx<0&&k<-60) z=0.0; 	
	else z=func_004ED178(func_004ED978(y/x));		
	switch (m) {
	    case 0: return       z  ;	
	    case 1: {
	    	      __uint32_t zh;
		      GET_HIGH_WORD(zh,z);
		      SET_HIGH_WORD(z,zh ^ 0x80000000);
		    }
		    return       z  ;	
	    case 2: return  pi-(z-pi_lo);
	    default: 
	    	    return  (z-pi_lo)-pi;
	}
}

