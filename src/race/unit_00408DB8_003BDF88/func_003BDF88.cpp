/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b) { (*this)[0]=a;(*this)[1]=b; }
 void set(float a,float b) { x=a;y=b; }
 V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
 V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v;return *this; }
 float &operator[](int i) {return *(float *)((char*)this+4*i);}
 float operator[](int i) const {return *(const float *)((const char*)this+4*i);}
 float length2() const {return x*x+y*y;}
 V &operator*=(float k) { x*=k;y*=k;return *this; }
 V normalized() const { float k; float n=length2();float one=1.0f;__asm__("rsqrt.s %0, %1, %2":"=f"(k):"f"(one),"f"(n));V t(*this);t*=k;return t; }
 float dot(const V &v) const {return x*v[0]+y*v[1];}
} __attribute__((aligned(16)));
struct Angle { float value; Angle(float f):value(f) {} } __attribute__((aligned(16)));
extern "C" float func_004EE530(float);
extern "C" void func_003E9C18(V *, const Angle &, const V *);
extern "C" int func_003BDF88(V *in,V *out) {
 V v((*in)[0],(*in)[2]);V r;V *dir=&r;int ret=0;
 if(v.length2()>0.0f) {
  v=v.normalized();
  if(v[1] < -0.5f) { *out=*in;ret=1; }
  else if(v[1] < 0.70710677f) {
   if(v[0]>0.0f) { dir->set(0.8660254f,-0.5f);func_003E9C18(out,1.5707963f-func_004EE530(dir->dot(v)),in); }
   else { dir->set(-0.8660254f,-0.5f);func_003E9C18(out,-(1.5707963f-func_004EE530(dir->dot(v))),in); }
   ret=1;
  }
 }
 return ret;
}
