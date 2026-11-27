/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b,float c) {x=a;y=b;z=c;}
 V(const V &v) {*(u128*)this=*(const u128*)&v;}
 V &operator=(const V &v) {*(u128*)this=*(const u128*)&v;return *this;}
} __attribute__((aligned(16)));
struct Q {float x,y,z,w;void clear(){w=1.0f;y=0.0f;z=0.0f;x=0.0f;}};
struct M {
 u128 a,b,c;
 M(const M &m){a=m.a;b=m.b;c=m.c;}
 M &operator=(const M&m){c=m.c;b=m.b;a=m.a;return *this;}
};
extern M D_005869E0;
struct S {char p[16];Q q;V v[9];V u[3];int e;char pe[12];M m;int a;float b,c;int d;float f;};
extern "C" int func_003DD798(S *s) {
 s->q.clear();
 for(int i=0;i<9;i++) s->v[i]=V(0.0f,0.0f,0.0f);
 for(int i=0;i<3;i++) s->u[i]=V(0.0f,0.0f,1.0f);
 float zero=0.0f;
 s->e=0;
 M *matrix=&s->m;
 *matrix=M(D_005869E0);
 s->a=0;s->b=zero;s->c=0x1.921fb4p+1f;s->d=0;s->f=zero;
}
