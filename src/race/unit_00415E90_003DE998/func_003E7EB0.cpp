/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
union Vec { struct { float x,y,z,w; }; u128 q; Vec() {} Vec(const Vec &v) { q=v.q; } Vec &operator=(const Vec &v) { q=v.q; return *this; } };
struct Angle { float v; };
extern "C" float func_004EE530(float);
extern "C" Vec *func_00453F60(Vec *,const Vec *,const Vec *);
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a),"f"(b)); return r; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a),"f"(b)); return r; }
static inline float clampf(const float &v,float lo,float hi) { return minf(maxf(v,lo),hi); }
extern "C" Angle *func_003E7EB0(Angle *out,const Vec *a,const Vec *b,const Vec *axis) {
 float bx=b->x,ax=a->x,by=b->y,ay=a->y,bz=b->z,az=a->z;
 float dot=ax*bx+ay*by+az*bz;
 float angle=0x1.921fb4p+0f-func_004EE530(clampf(dot,-1.0f,1.0f));
 Vec cross;
 Vec tmp;
 Vec *pt=&tmp;
 func_00453F60(pt,axis,a);
 Vec *p=&cross;
 p->q=pt->q;
 if (b->x*p->x+b->y*p->y+b->z*p->z<0.0f) angle=-angle;
 out->v=angle;
 return out;
}
