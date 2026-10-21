/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 union {u128 bits; struct {float x,y,z,w;};};
 V() {} V(const V &v) {bits=v.bits;}
 V(float a,float b,float c) {x=a;y=b;z=c;}
 V &operator=(const V &v) {bits=v.bits;return *this;}
 float &operator[](int i) {return (&x)[i];}
 const float &operator[](int i) const {return (&x)[i];}
 V &operator-=(const V &v) {(*this)[0]-=v[0];(*this)[1]-=v[1];(*this)[2]-=v[2];return *this;}
};
static inline V operator-(const V &a,const V &b) {V r(a);r-=b;return r;}
struct M {float a[9]; M() {} M(float a0,float a3,float a6,float a1,float a4,float a7,float a2,float a5,float a8) {a[0]=a0;a[3]=a3;a[6]=a6;a[1]=a1;a[4]=a4;a[7]=a7;a[2]=a2;a[5]=a5;a[8]=a8;} };
struct Line {V pos,dir;};
struct Tri {V a,b,c;};
extern "C" int func_003E8818(const M*,M*) throw();
extern "C" void func_0044FC00(V*,const M*,const V*);
static inline V transform(const M &m,const V &v) {V r;func_0044FC00(&r,&m,&v);return r;}
extern "C" int func_003EAB28(const Line *line,const Tri *tri,float *t,float *u,float *v) {
 V ab=tri->b-tri->a;
 V ac=tri->c-tri->a;
 M m(line->dir[0],-ab[0],-ac[0],line->dir[1],-ab[1],-ac[1],line->dir[2],-ab[2],-ac[2]);
 M inv;
 if(!func_003E8818(&m,&inv)) return 0;
 V d(tri->a[0]-line->pos[0],tri->a[1]-line->pos[1],tri->a[2]-line->pos[2]);
 d=transform(inv,d);
 *t=d[0];*u=d[1];*v=d[2];
 return 1;
}
