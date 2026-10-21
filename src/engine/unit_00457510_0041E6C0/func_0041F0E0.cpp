/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Point { Vec pos; float weight; };
struct Obj { unsigned count; char p4[8]; float blend; char p10[12]; float start; char p20[12]; float end; Point points[1]; };
struct Node {char pad[16]; Node *next; int u14; void *car;};
struct List {char pad[20]; Node *head;};
struct Context {char pad[0x60]; List *list;};
static inline float minimum(float a,float b) {float r;__asm__("min.s %0, %1, %2":"=f"(r):"0"(a),"f"(b));return r;}
static inline float maximum(float a,float b) {float r;__asm__("max.s %0, %1, %2":"=f"(r):"0"(a),"f"(b));return r;}
static inline float root(float a) {__asm__("sqrt.s %0, %0":"+f"(a));return a;}
extern "C" float func_002E5E70(void *,float);
extern "C" float func_004A5D18(float) throw();
static inline float atten(float d, float near) { float f=1.0f; if (!(d<near)) f=d/near; return f; }
static inline float dot(float x,float y,float z,Vec *v) { return x*v->x+y*v->y+z*v->z; }
static inline bool nonempty(unsigned n) { return n != 0; }
extern "C" void func_0041F0E0(Obj *p,Vec *out,Context *ctx,Vec *pos,Vec *dir,Vec *velocity) {
 float blend=1.0f;
 List *list=ctx->list;
 float start=p->start,end=p->end;
 if(start!=end) {
  float weight=1.0f;
  int reverse=end<start;
  Node *node=list->head;
  blend=0.0f;
  while(node) {
   float f=func_002E5E70(node->car,0.0f);
   if(!reverse) {if(start<=f && f<=end) blend+=weight;}
   else {if(start<=f || f<=end) blend+=weight;}
   node=node->next;
   weight*=0x1.999998p-1f;
  }
  if(blend>=1.0f) blend=1.0f;
  float old=p->blend;
  if(blend<old) old-=minimum(old-blend,0x1.6c16cp-8f);
  else old+=minimum(blend-old,0x1.111110p-7f);
  blend=old;
  p->blend=blend;
 }
 float sumY=0.0f,sumX=0.0f,sumZ=0.0f;
 unsigned i=0;
 unsigned count=p->count;
 if(count) {
 float zero=0.0f;
 float *xyz=&p->points[0].pos.z;
 float *weights=&p->points[0].weight;
 do {
  float x=xyz[-2]-pos->x;
  float y=xyz[-1]-pos->y;
  float z=xyz[0]-pos->z;
  float w=*weights*blend;
  xyz+=4;weights+=4;
  float distance=root(x*x+y*y+z*z);
  if(distance==zero) distance=1.0f;
  x/=distance;y/=distance;z/=distance;
  float factor=atten(distance,32.0f);
  w/=factor;
  float v=dot(x,y,z,velocity);
  float pan=dot(x,y,z,dir);
  v=0x1.618bf0p+2f/(0x1.618bf0p+2f-v);
  pan=(pan+1.0f)*0.5f;
  pan=maximum(pan,zero);pan=minimum(pan,1.0f);
  sumZ+=(v-1.0f)*w;
  sumX+=func_004A5D18((1.0f-pan)*0x1.921fb4p+0f)*w;
  sumY+=func_004A5D18((pan+zero)*0x1.921fb4p+0f)*w;
 ++i; count=p->count;
 } while(i<count);
 }
 if(nonempty(count)) sumZ/=count;
 out->x+=sumX;out->y+=sumY;out->z+=sumZ;
}
