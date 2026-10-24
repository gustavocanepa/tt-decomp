/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) {*(u128 *)this=*(const u128 *)&v;}
 V &operator=(const V &v) {*(u128 *)this=*(const u128 *)&v;return *this;}
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V operator*(float t) const {V r(*this);r[0]*=t;r.y*=t;r.z*=t;return r;}
 V operator+(const V &v) const {V r(*this);r[0]+=v.x;r[1]+=v.y;r[2]+=v.z;return r;}
} __attribute__((aligned(16)));
struct Obj {V pos,rot;};
extern "C" void func_0044F728(V *,const V *,const V *,float);
extern "C" void func_003E1A68(Obj *o,const Obj *a,const Obj *b,float t) {
 o->pos=a->pos*(1.0f-t)+b->pos*t;
 func_0044F728(&o->rot,&a->rot,&b->rot,t);
}
