/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec {float x,y,z,w;};
struct Mat { Vec v[4]; };
static inline float get(const float *p) {return *p;}
static inline float mx(const Mat *a) {return a->v[3].x;}
static inline float my(const Mat *a) {return a->v[3].y;}
static inline float mw(const Mat *a) {return a->v[3].w;}
static inline void mul(Vec *o,const Mat *a,const Vec *b) {
 const float *w=&b->w;
 o->x=a->v[0].x*b->x+a->v[1].x*b->y+mx(a)*get(w);
 o->y=a->v[0].y*b->x+a->v[1].y*b->y+my(a)*get(w);
 o->z=0;
 o->w=mw(a)*get(w);
}
extern "C" void func_00444F28(Mat *o,const Mat *a,const Mat *b) {
 int k=16,k3=48;
 Vec *o1=(Vec*)((char*)o+k);
 Vec *o3=(Vec*)((char*)o+k3);
 const Vec *b1=(const Vec*)((const char*)b+k);
 const Vec *b3=(const Vec*)((const char*)b+k3);
 mul(&o->v[0],a,&b->v[0]);
 mul(o1,a,b1);
 o->v[2].y=0;o->v[2].w=0;o->v[2].z=1;o->v[2].x=0;
 mul(o3,a,b3);
}
