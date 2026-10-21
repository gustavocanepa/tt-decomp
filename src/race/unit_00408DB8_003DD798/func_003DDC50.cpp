/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b,float c) {x=a;y=b;z=c;}
 V(const V &v) {*(u128*)this=*(const u128*)&v;}
 V &operator=(const V &v) {*(u128*)this=*(const u128*)&v;return *this;}
} __attribute__((aligned(16)));
extern "C" void func_0044E020(void*,const void*,float);
struct Q {
 V v; float angle;
 Q(const V &axis,float a) {angle=a;func_0044E020(&v,&axis,a);}
};
struct S {char pad[16];Q q;char rest[0xF0-16-sizeof(Q)];float matrix[12];};
extern "C" V func_003E6350(const Q*,const V*);
extern "C" void func_0044FC00(V*,const float*,const V*);
static inline V transform(const float *m,const V *v) { V t;func_0044FC00(&t,m,v);return t;}
extern "C" V func_003DDC50(S *s,const float *angle,float x,float y) {
 Q *rot=&s->q;
 V v(-x,y,0.0f);
 if (*angle != 0.0f) {
  V axis(-y,x,0.0f);
  Q q(axis,*angle);
  v=func_003E6350(&q,&v);
 }
 return func_003E6350(rot,&V(transform(s->matrix,&v)));
}
