/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
 V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v;return *this; }
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 const float &operator[](int i) const {return *(const float *)((const char *)this+i*4);}
 V operator-(const V &v) const {V r(*this);r[0]-=v[0];r[1]-=v[1];r[2]-=v[2];return r;}
} __attribute__((aligned(16)));
struct Obj {char pad[0x50];V a,b;};
extern "C" void func_003D91C8(Obj *,const V *,const V *) throw();
extern "C" void func_003D9778(Obj *o,const V *a,const V *b,const V *c,const V *d) {
 func_003D91C8(o,a,d);
 o->a=*b-*a;
 o->b=*c-*a;
}
