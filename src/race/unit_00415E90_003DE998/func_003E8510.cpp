/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
 V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v;return *this; }
 V &operator*=(float t) {x*=t;y*=t;z*=t;return *this;}
 V operator*(float t) const {V r(*this);r*=t;return r;}
 float dot(const V &v) const {float vy=v.y;return x*v.x+y*vy+z*v.z;}
} __attribute__((aligned(16)));
extern "C" void func_003E8510(V *out,const V *a,const V *b) {
 *out=*b*(a->dot(*b));
}
