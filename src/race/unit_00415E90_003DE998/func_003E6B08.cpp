/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q {
 float x,y,z,w;
 float &operator[](const int &i){return ((float*)this)[i];}
 Q(){} Q(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
 Q(const Q&q){*(u128*)this=*(const u128*)&q;}
 Q &operator=(const Q&q){*(u128*)this=*(const u128*)&q;return *this;}
 Q &operator*=(float f){x*=f;y*=f;z*=f;w*=f;return *this;}
} __attribute__((aligned(16)));
extern "C" void func_004A6328(float *,float *,float);
extern "C" void func_00453E80(Q *,Q *,Q *);
static inline void add(Q *q,Q a){func_00453E80(q,q,&a);}
extern "C" Q *func_003E6B08(Q *q,float *angle){
 float s,c;
 if(*angle!=0.0f){
  func_004A6328(&s,&c,*angle*0.5f);
  float x=q->x,y=q->y,z=q->z,w=q->w;
  float f=(x*x+y*y+z*z+w*w)*2.0f-1.0f;
  float a=(*q)[1],b=-(*q)[0],cc=(*q)[3],d=(*q)[2];
  d=-d;a*=f;b*=f;
  Q t(a,b,cc,d);
  t*=s;
  *q*=c;
  add(q,t);
 }
 return q;
}
