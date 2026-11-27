/* compiler: ee-gcc2.96-stl */
static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct V { float x,y; };
struct Out { int kind; float x,y; int id; };
extern "C" float func_00378888(V *,V *,V *) throw();
static inline float root(float a) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(a)); return r; }
extern "C" float func_00378948(Out *o,V *a,V *b,int ai,int bi,V *p,V *q,float t) {
 float dist=func_00378888(p,q,a);
 float second=func_00378888(p,q,b);
 V *near=b; int id=bi;
 V *far=a;
 float result=0.0f;
 if(second<dist) { far=near; near=a; id=ai; }
 float dx=q->x-p->x;
 float dy=q->y-p->y;
 float scaled=t*t*(dx*dx+dy*dy);
 float x,y;
 dx=near->x-far->x; dy=near->y-far->y;
 if(absf(dy)<absf(dx)) {
  float r=dy/dx;
  float sq=scaled/(r*r+1.0f);
  __asm__("sqrt.s %0, %1" : "=f"(x) : "f"(sq));
  if(dx<0.0f) x=-x;
  y=x*dy/dx;
 } else {
  float r=dx/dy;
  float sq=scaled/(r*r+1.0f);
  __asm__("sqrt.s %0, %1" : "=f"(y) : "f"(sq));
  if(dy<0.0f) y=-y;
  x=y*dx/dy;
 }
 o->kind=1;
 float len=x*x+y*y;
 o->x=p->x+x;
 o->y=p->y+y;
 o->id=-1;
 dx=near->x-p->x; dy=near->y-p->y;
 float d=dx*dx+dy*dy;
 if(d<=len) {
  o->kind=2;
  o->x=near->x;
  o->y=near->y;
  o->id=id;
  if(len>0.0f) result=(len-d)/len;
 }
 return result;
}
