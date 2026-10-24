/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
static inline float rsqrt(float f) {float r;asm("rsqrt.s %0, %1, %2":"=f"(r):"f"(1.0f),"f"(f));return r;}
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) {*(u128 *)this=*(const u128 *)&v;}
 V &operator=(const V &v) {*(u128 *)this=*(const u128 *)&v;return *this;}
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V normalised() const {V r(*this);V *p=&r;float s=rsqrt(p->x*p->x+p->y*p->y+p->z*p->z);p->x*=s;p->y*=s;p->z*=s;return r;}
} __attribute__((aligned(16)));
extern V D_00585350;
extern "C" V func_003E77F0(const V *a) {
 V v;
 if(a->x!=0.0f) {v.x=-a->y;v.y=a->x;v.z=0.0f;}
 else if(a->y!=0.0f) {v.x=0.0f;v.y=-a->z;v.z=a->y;}
 else if(a->z!=0.0f) {v.x=a->z;v.y=0.0f;v.z=-a->x;}
 else {return D_00585350;}
 return v.normalised();
}
