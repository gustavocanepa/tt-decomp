/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 union {u128 bits; struct {float x,y,z,w;};};
 V() {} V(const V &v) {bits=v.bits;}
 V &operator=(const V &v) {bits=v.bits;return *this;}
 V &operator*=(float f) {x*=f;y*=f;z*=f;return *this;}
 float squared() const {return x*x+y*y+z*z;}
};
extern "C" void func_003E8668(V*,const V*,const V*);
extern "C" void func_003E7EB0(float*,const V*,const V*,const V*) throw();
static inline V projected(const V *a,const V *b) {V r;func_003E8668(&r,a,b);return r;}
static inline V scaled(const V &a,float f) {V r(a);r*=f;return r;}
static inline float rsqrt(float a) {float r;asm("rsqrt.s %0, %1, %2":"=f"(r):"f"(1.0f),"f"(a));return r;}
extern "C" float *func_003E7FC8(float *out,const V *a,const V *b,const V *axis) {
 V va;
 V vb;
 func_003E8668(&va,a,axis);
 func_003E8668(&vb,b,axis);
 float sa=va.squared();
 float sb=vb.squared();
 if(sa!=0.0f && sb!=0.0f) {
  float ra=rsqrt(sa),rb=rsqrt(sb);
  va=scaled(va,ra);
  vb=scaled(vb,rb);
  func_003E7EB0(out,&va,&vb,axis);
 } else *out=0.0f;
 return out;
}
