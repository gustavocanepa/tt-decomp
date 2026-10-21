/* compiler: ee-gcc2.96-nsa-g */
/* __kernel_tan from newlib 1.9.0 libm: k_tan.c (fdlibm, Sun Microsystems), see THIRD_PARTY.md. */
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

double func_004ED978(double);

static const double 
one   =  1.00000000000000000000e+00, 
pio4  =  7.85398163397448278999e-01, 
pio4lo=  3.06161699786838301793e-17, 
T[] =  {
  3.33333333333334091986e-01, 
  1.33333333333201242699e-01, 
  5.39682539762260521377e-02, 
  2.18694882948595424599e-02, 
  8.86323982359930005737e-03, 
  3.59207910759131235356e-03, 
  1.45620945432529025516e-03, 
  5.88041240820264096874e-04, 
  2.46463134818469906812e-04, 
  7.81794442939557092300e-05, 
  7.14072491382608190305e-05, 
 -1.85586374855275456654e-05, 
  2.59073051863633712884e-05, 
};
	double func_004F33F0(double x, double y, int iy)
{
	double z,r,v,w,s;
	__int32_t ix,hx;
	GET_HIGH_WORD(hx,x);
	ix = hx&0x7fffffff;	
	if(ix<0x3e300000)			
	    {if((int)x==0) {			
	        __uint32_t low;
		GET_LOW_WORD(low,x);
		if(((ix|low)|(iy+1))==0) return one/func_004ED978(x);
		else return (iy==1)? x: -one/x;
	    }
	    }
	if(ix>=0x3FE59428) { 			
	    if(hx<0) {x = -x; y = -y;}
	    z = pio4-x;
	    w = pio4lo-y;
	    x = z+w; y = 0.0;
	}
	z	=  x*x;
	w 	=  z*z;
	r = T[1]+w*(T[3]+w*(T[5]+w*(T[7]+w*(T[9]+w*T[11]))));
	v = z*(T[2]+w*(T[4]+w*(T[6]+w*(T[8]+w*(T[10]+w*T[12])))));
	s = z*x;
	r = y + z*(s*(r+v)+y);
	r += T[0]*s;
	w = x+r;
	if(ix>=0x3FE59428) {
	    v = (double)iy;
	    return (double)(1-((hx>>30)&2))*(v-2.0*(x-(w*w/(w+v)-r)));
	}
	if(iy==1) return w;
	else {		
	    double a,t;
	    z  = w;
	    SET_LOW_WORD(z,0);
	    v  = r-(z - x); 	
	    t = a  = -1.0/w;	
	    SET_LOW_WORD(t,0);
	    s  = 1.0+t*z;
	    return t+a*(s+t*v);
	}
}
