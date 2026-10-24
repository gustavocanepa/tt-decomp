/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 union {u128 bits; struct {float x,y,z,w;};};
 V() {} V(const V &v) {bits=v.bits;}
 V &operator=(const V &v) {bits=v.bits;return *this;}
 void scale(float f) {x*=f;y*=f;z*=f;}
 float &operator[](int i) {return (&x)[i];}
 const float &operator[](int i) const {return (&x)[i];}
 V &operator+=(const V &v) {(*this)[0]+=v[0];(*this)[1]+=v[1];(*this)[2]+=v[2];return *this;}
 V operator*(float f) const {V r(*this);r.scale(f);return r;}
 V operator+(const V &v) const {V r(*this);r+=v;return r;}
};
struct Angle {float v; Angle() {}  Angle(const Angle &a) {v=a.v;}};
struct Obj {char pad[0x68];float h,w;};
struct S {char pad[0xe0];float h;};
extern "C" V func_003DDAF0(S*,float,float,float,float) throw();
extern "C" void func_004A6328(float,float*,float*);
static inline void sincos_(const Angle &a,float *s,float *c) {func_004A6328(a.v,s,c);}
static inline float height(Obj *o,S *s) {float h=o->h;return s->h+h;}
extern "C" void func_003DE998(Obj *self,V *out,const Angle *a,const Angle *b,S *s,float t) {
 float sa,ca,sb,cb;
 Angle angle; float &value=angle.v;
 value=a->v; sincos_(angle,&sa,&ca);
 value=b->v; sincos_(angle,&sb,&cb);
 *out=func_003DDAF0(s,sa,ca,height(self,s),self->w)*(1.0f-t)+func_003DDAF0(s,sb,cb,height(self,s),self->w)*t;
}
