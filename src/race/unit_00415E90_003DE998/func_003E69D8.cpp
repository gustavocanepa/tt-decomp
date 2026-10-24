/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 float &operator[](const int &i){return ((float*)this)[i];}
 V() {}
 V(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
 V(const V &v) {*(u128 *)this=*(const u128 *)&v;}
 V &operator*=(float s) {x*=s;y*=s;z*=s;w*=s;return *this;}
 float squared() const {return x*x+y*y+z*z+w*w;}
} __attribute__((aligned(16)));
extern "C" void func_004A6328(float *,float *,float);
extern "C" void func_00453E80(V *,V *,const V *);
static inline float negative(float a) {return -a;}
static inline float copy(float a) {return a;}
extern "C" V *func_003E69D8(V *q,const float *ang) {
 float s,c;
 if(*ang!=0.0f) {
  func_004A6328(&s,&c,*ang*0.5f);
  float d=q->squared(); d=d+d-1.0f;
  V v(negative((*q)[2])*d,copy((*q)[3]),(*q)[0]*d,negative((*q)[1]));
  v*=s;
  *q*=c;
  V t(v);
  func_00453E80(q,q,&t);
 }
 return q;
}
