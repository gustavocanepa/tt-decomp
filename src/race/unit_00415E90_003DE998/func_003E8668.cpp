/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
 V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v;return *this; }
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V operator-(const V &v) const {V r(*this);r[0]-=v.x;r[1]-=v.y;r[2]-=v.z;return r;}
 V &operator*=(float t) {x*=t;y*=t;z*=t;return *this;}
 V operator*(float t) const {V r(*this);r*=t;return r;}
 float dot(const V &v) const {float vx=v.x,vy=v.y,vz=v.z;return x*vx+y*vy+z*vz;}
} __attribute__((aligned(16)));
extern "C" void func_003E8668(V *out,const V *a,const V *b) {
 *out=*a-*b*(a->dot(*b));
}
