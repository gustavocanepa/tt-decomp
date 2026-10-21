/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
 V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v;return *this; }
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V operator-(const V &v) const {V r(*this);r[0]-=v.x;r[1]-=v.y;r[2]-=v.z;return r;}
 V operator+(const V &v) const {V r(*this);r[0]+=v.x;r[1]+=v.y;r[2]+=v.z;return r;}
 V operator*(float t) const {V r(*this);r[0]*=t;r[1]*=t;r[2]*=t;return r;}
 float dot(const V &v) const {return x*v.x+y*v.y+z*v.z;}
} __attribute__((aligned(16)));
extern "C" void func_003E8580(V *out,const V *a,const V *b,const V *dir) {
 *out=*dir*((*a-*b).dot(*dir))+*b;
}
