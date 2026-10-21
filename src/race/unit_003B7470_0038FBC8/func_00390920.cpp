/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Light { char pad[0x40]; float width, height; char pad48[12]; float r,g,b; };
struct Entry { float x,y,z; Light *light; int flag; float a,dx,dy,n; };
struct Source { int index; char pad[0x18]; float phase; };
struct Entry2 { float x,y,z,a; int flag; Source *source; };
struct Param { float r,g,b,sx,sy,a,p18,c,b1,a2,p28,p2c,blink,phase,p38; };
struct Self {
 char pad[0x7c]; void *p7c; void *p80; void *p84;
 char pad88[0xA08-0x88]; int active; float pos[3]; float n,r,g,b;
 int enabled, mode, type, count; Entry entries[100]; int count2; Entry2 entries2[100];
 char pad21ac[0x44]; Param param; Param params[1];
};
struct Quad { float x,y,z,w; };
extern "C" {
void *func_00464990();
void *func_004649A0();
void *func_00464C28();
void *func_00464EE0();
void func_00466198(Self *, int, void *, void *, float,float,float,float,float,float,float,float);
void func_00466398(Self *, Entry *, Quad *, float,float,float,float,float);
void func_004665F8(Self *, float *, void *, float,float,float,float);
int func_00467728(void *);
void func_0046F0F8(int);
int func_004702D8(int,float);
void func_00473050();
void func_004730A8();
void func_00478C98(int);
float func_004A5D18(float) throw();
}
static inline float rsqrt(float a,float b) { float r; __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline void *get(Self *s) { void *p; if(s->p80) p=s->p80; else p=func_004649A0(); return p; }
static inline float length2(float x,float y) { return x*x+y*y; }
static inline bool near(const float &a,const float &b) { float d=a-b; if(d<0.0f) d=-d; return d<0.01f; }
extern "C" void func_00390920(Self *s) {
 if(s->active || s->count || s->count2) {
  func_0046F0F8(17); func_00478C98(5); func_00478C98(15); func_00478C98(4); func_00478C98(3); func_004702D8(72,0.0f);
  if(s->enabled) {
   if(s->mode==0 && s->p7c) func_00467728(s->p7c);
   if(s->enabled) {
    void *p=func_00464990();
    switch(s->mode) { case 1:p=func_00464EE0();break;case 2:p=func_00464C28();break; }
    func_004665F8(s,s->pos,p,s->n,s->r,s->g,s->b);
   }
  }
  if(s->p84 && (s->count || s->count2)) func_00467728(s->p84);
  int i=0;
  func_00473050();
  if (s->count>0) {
  char *walk=(char *)s;
  do {
   void *p=get(s);
   Entry *e=(Entry *)(walk+0xA38);
   Param *pm=&s->param;
   float z=-e->z;
   Light *l=e->light;
   int flag=e->flag;
   float att=1.0f/(z*z*pm->a2+z*pm->b1+pm->c);
   float r=l->r*s->param.r*att;
   float g=l->g*s->param.g*att;
   float b=l->b*s->param.b*att;
   if(!flag && !near(l->width,l->height)) {
    Quad q;
    float sy=pm->sy;
    float y=e->dy;
    y*=sy;
    float x=e->dx*sy;
    float inv=rsqrt(l->height,length2(e->dx,e->dy));
    q.x=x; q.y=y; q.z=-y*inv; q.w=x*inv;
    func_00466398(s,e,&q,e->n,r,g,b,s->param.a);
   } else {
    float w=l->width;
    int f=flag!=0;
    func_00466198(s,s->type?f+2:f,e,p,e->n,r,g,b,e->a,pm->sx*w,s->param.a,pm->sy*w);
   }
   i++; walk+=0x24;
  } while(i<s->count);
  }
  i=0;
  func_004730A8(); func_00473050();
  if(s->count2>0) {
  char *walk=(char *)s;
  do {
   void *p=get(s);
   Entry2 *e=(Entry2 *)(walk+0x184C);
   Source *src=e->source;
   float z=-e->z;
   Param *pm=&s->params[src->index];
   float att=1.0f/(z*z*pm->a2+z*pm->b1+pm->c);
   walk+=0x18;
   if(pm->blink>0.0f) att*=func_004A5D18((pm->phase+src->phase)*0x1.921fb4p+2f)*0.5f+0.5f;
   float r=pm->r*att, g=pm->g*att, b=pm->b*att;
   int f=e->flag!=0;
   func_00466198(s,s->type?f+2:f,e,p,0.5f,r,g,b,e->a,pm->sx,pm->a,pm->sy);
   i++;
  } while(i<s->count2);
  }
  func_004730A8(); func_0046F0F8(15);
 }
}
