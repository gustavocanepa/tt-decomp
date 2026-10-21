/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
union V2 {
 struct { float x,y; }; u128 q;
 V2() {} V2(const V2 &v) { q=v.q; }
 void normalize() {
  float s=1.0f, d=x*x+y*y;
  __asm__("rsqrt.s %0, %1, %2":"=f"(s):"f"(s),"f"(d));
  x*=s; y*=s;
 }
 V2 &operator=(const V2 &v) { q=v.q; return *this; }
};
static inline float absf(float x) {float r; __asm__("abs.s %0, %1":"=f"(r):"f"(x));return r;}
struct Angle { float v; Angle() {} Angle(const Angle &a) {v=a.v;} float abs() const { return absf(v); } };
extern "C" float func_004EE530(float);
extern "C" float func_004A5D18(float) throw();
extern "C" Angle func_003E7A00(const V2 *,const V2 *);
static inline float sqroot(float x) {float r; __asm__("sqrt.s %0, %1":"=f"(r):"f"(x));return r;}
static inline float minf(const float &a,const float &b) {float r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline V2 normalized(const V2 &v) {
 V2 r(v);
 r.normalize();
 return r;
}
extern "C" int func_003E2490(float *a,float *b,float *c,float *d,float x,float y,float z,float w) {
 float roots[2];
 float yy=y*y;
 float sum=x+z;
 float k=sum*-2.0f;
 float disc=(((x*x)+yy+(z*z))-(w*w))-(2.0f*x*z);
 disc=(yy*k*k)-(x*16.0f*z*disc);
 if(disc<0.0f) {
  if(y<sum) {
   float t=0x1.921fb4p+0f-func_004EE530(y/sum);
   *a=t; *b=t; *c=0x1.2d97c6p+2f-*a; *d=0x1.921fb4p+0f-*a;
  } else {
   *a=0.0f; *b=0.0f; *c=0x1.921fb4p+1f; *d=0x1.921fb4p+1f;
  }
  return 0;
 }
 __asm__("sqrt.s %0, %0":"+f"(disc));
 float center=-y*k;
 float denom=x*8.0f*z;
 roots[0]=(center+disc)/denom;
 roots[1]=(center-disc)/denom;
 if(roots[0]>=-1.0f && roots[0]<=1.0f && (roots[1]<-1.0f || roots[1]>1.0f)) disc=roots[0];
 else if(roots[1]>=-1.0f && roots[1]<=1.0f && (roots[0]<-1.0f || roots[0]>1.0f)) disc=roots[1];
 else if(roots[0]>=-1.0f && roots[0]<=1.0f && roots[1]>=-1.0f && roots[1]<=1.0f) disc=minf(roots[0],roots[1]);
 else disc=-1.0f;
 *a=absf(0x1.921fb4p+0f-func_004EE530(disc));
 *b=*a;
 V2 u,v;
 V2 *pu=&u,*pv=&v;
 k=func_004A5D18(*a);
 float vy=(x-z)*k;
 pu->x=y-sum*disc; pu->y=vy;
 *pu=normalized(*pu);
 pv->x=-disc; pv->y=k;
 *d=func_003E7A00(pu,pv).abs();
 *c=0x1.921fb4p+2f-*a-*b-*d;
 return 1;
}
