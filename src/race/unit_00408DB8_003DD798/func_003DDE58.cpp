/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
 V(const V &v) { *(u128*)this=*(const u128*)&v; }
 V &operator=(const V &v) { *(u128*)this=*(const u128*)&v;return *this; }
} __attribute__((aligned(16)));
struct S {char pad[16];V q;};
extern "C" int func_003DD798() throw();
extern "C" V *func_00453FD0(V *, const V *,const V *);
static inline V rotate(const V &a,const V &b) { V r;func_00453FD0(&r,&a,&b);return r; }
extern "C" int func_003DDE58(S *s) {
 func_003DD798();
 V a(0.0f,0.0f,0.0f,1.0f);
 V rot(rotate(a,V(0.0f,1.0f,0.0f,0.0f)));
 s->q=rot;
}
