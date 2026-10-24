/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b,float c) {x=a;y=b;z=c;}
 V(const V &v) {*(u128*)this=*(const u128*)&v;}
 V &operator=(const V &v) {*(u128*)this=*(const u128*)&v;return *this;}
 float &elem(int i){return ((float*)this)[i];}
 const float &elem(int i)const{return ((const float*)this)[i];}
 V operator+(const V &v) const { V r(*this);r.elem(0)+=v.elem(0);r.elem(1)+=v.elem(1);r.elem(2)+=v.elem(2);return r;}
} __attribute__((aligned(16)));
struct S {char p[0x50];V pos;char p60[0xF0-0x60];float matrix[12];};
extern "C" void func_0044FC00(V*,const float*,const V*);
static inline V transform(const float*m,const V*v){V t;func_0044FC00(&t,m,v);return t;}
extern "C" V func_003DDAF0(S *s,float x,float y,float z,float w) {
 V input(-z*x,z*y,-w);
 return transform(s->matrix,&input)+s->pos;
}
