/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 union {u128 bits; struct {float x,y,z,w;};};
 V() {} V(const V &v) {bits=v.bits;}
 V(float a,float b) {x=a;y=b;}
 V &operator=(const V &v) {bits=v.bits;return *this;}
 float &operator[](int i) {return (&x)[i];}
 const float &operator[](int i) const {return (&x)[i];}
};
struct M {float a[4]; M() {} M(float a0,float a2,float a1,float a3) {a[0]=a0;a[2]=a2;a[1]=a1;a[3]=a3;} };
struct Line {V pos,dir;};
extern "C" int func_003E8728(const M*,M*) throw();
extern "C" void func_0044FAE0(V*,const M*,const V*);
static inline V transform(const M &m,const V &v) {V r;func_0044FAE0(&r,&m,&v);return r;}
extern "C" int func_003EAA38(const Line *a,const Line *b,float *t,float *u) {
 M m(a->dir[0],-b->dir[0],a->dir[1],-b->dir[1]);
 M inv;
 if(!func_003E8728(&m,&inv)) return 0;
 V d(b->pos[0]-a->pos[0],b->pos[1]-a->pos[1]);
 d=transform(inv,d);
 *t=d[0];*u=d[1];
 return 1;
}
