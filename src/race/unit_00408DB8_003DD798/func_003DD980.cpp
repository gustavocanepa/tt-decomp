/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
 V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v;return *this; }
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V operator*(float t) const {V r(*this);r[0]*=t;r.y*=t;r.z*=t;return r;}
 V operator+(const V &v) const {V r(*this);r[0]+=v.x;r[1]+=v.y;r[2]+=v.z;return r;}
} __attribute__((aligned(16)));
struct S {char pad[0x60];V a,b,c;char pad90[0xa0];float t;};
extern "C" V func_003DD980(S *s) {
 float t=s->t;
 if(t>=0.0f && t<=1.0f) return s->a*(1.0f-t)+s->b*t;
 else if(t<=2.0f) {t-=1.0f;return s->b*(1.0f-t)+s->c*t;}
 else {t-=2.0f;return s->c*(1.0f-t)+s->a*t;}
}
