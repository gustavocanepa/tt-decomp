/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b,float c) {x=a;y=b;z=c;}
 V(const V &v) {*(u128*)this=*(const u128*)&v;}
 V &operator=(const V &v) {*(u128*)this=*(const u128*)&v;return *this;}
} __attribute__((aligned(16)));
struct Q { V v; float angle; };
struct S {char pad[16];Q q;char rest[0xF0-16-sizeof(Q)];float matrix[12];};
extern "C" V func_003E6350(const Q*,const V*);
extern "C" void func_0044FC00(V*,const float*,const V*);
static inline V transform(const float *m,const V *v) { V t;func_0044FC00(&t,m,v);return t;}
extern "C" V func_003DDBA8(S *s,int flip,float x,float y) {
 Q *rot=&s->q;
 V v;
 if (!flip) v = V(y,x,0.0f); else v = V(-y,-x,0.0f);
 return func_003E6350(rot,&V(transform(s->matrix,&v)));
}
