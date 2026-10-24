/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x,y,z; };
struct Info { int first; float start,end; int count,extra; short *types; };
struct Inner { char pad[0xC0]; int ids[6]; char pd8[0x48]; float lasttime[6]; char p138[0x18]; float positions[6][3]; };
struct Obj { union {
 struct { V3 out[3]; float zoom; int enabled,unused; int ok,okzoom; int flag[6]; char p50[0x30]; float time[6]; char p98[0x18]; int current[6]; int ids[6]; int frame[6]; char pf8[0x18]; int prev[6]; float lasttime[6]; float angle[6]; V3 positions[6]; V3 points[6][4]; } a;
 struct { char pad[8]; Inner inner; } b;
}; };
extern "C" void *func_002F04D8(void *,int);
extern "C" float func_002E5E40(void *,float);
extern "C" float func_002E5EA0(void *,float);
extern "C" float func_002E5ED0(void *,float);
extern "C" float func_002E5F60(void *,float);
extern "C" void func_003EEC90(void *);
extern "C" void func_003EECA0(void *,int,void *);
extern "C" int GT4_Motion__MotionSetPlayer__getPlayListElementInformation(Info *,void *,int,float);
extern "C" int func_003EF148(void *,void *,int,int,float,float);
extern "C" int func_003EF708(void *,void *,int,int,float,float);
extern "C" int func_003F07C0(void *,int,const char *,float *,float,float);
extern "C" int func_00394DC0(void *,void *,void *,void *,void *,void *,int,int,int,float) throw();
extern char D_005F7C20[],D_005F7C30[];
static inline void init(Info *p,float z) {p->first=0;p->start=z;p->end=z;p->count=0;p->extra=0;p->types=0;}
static inline void set(float *x,float *y,float *z,float a,float b,float c) {*x=a;*y=b;*z=c;}
static inline void setPos(Inner *p,int id,float x,float y,float z) { p->positions[id][0]=x; p->positions[id][1]=y; p->positions[id][2]=z; }
extern "C" int Pitmen__Camera__computeCamera(Obj *self,void *motion,void *offset,void *ctx,int id,int sequence) {
 Info info; int player[4]; V3 camera[3]; float coords[2]; int good[3];
 int result=-1;
 if (!self->a.enabled || !motion || !ctx || id<0 || id>=6 || self->a.current[id]<0) {
  self->a.ok=0;self->a.okzoom=0;self->a.flag[id]=0;return -1;
 }
 init(&info,0.0f);
 void *car=func_002F04D8(ctx,id);
 func_003EEC90(player);
 func_003EECA0(player,0,motion);
 if(GT4_Motion__MotionSetPlayer__getPlayListElementInformation(&info,motion,self->b.inner.ids[id],self->a.time[id])) {
  int n=0;
  if(self->b.inner.lasttime[id]!=info.start) {
   int count=info.count;
   if(sequence>0) {if(count>=2) n=sequence%(count-1)+1;}
   self->a.frame[id]=n;
   self->b.inner.lasttime[id]=info.start;
   int value=info.types ? info.types[n] : 0;
   result=value;
   if(self->a.prev[id]!=result) {
    self->a.angle[id]=func_002E5F60(car,0.0f);
    float x=func_002E5E40(car,0.0f);
    float y=func_002E5EA0(car,0.0f);
    float z=func_002E5ED0(car,0.0f);
    setPos(&self->b.inner,id,x,y,z);
    self->a.prev[id]=result;
   }
  }
 }
 int mode=0;
 self->a.ok=func_003EF148(player,camera,self->b.inner.ids[id],0,self->a.time[id],(float)self->a.frame[id]);
 if(self->a.ok) {
  good[0]=func_003F07C0(player,self->b.inner.ids[id],D_005F7C20,&coords[0],self->a.time[id],(float)self->a.frame[id]);
  good[1]=func_003F07C0(player,self->b.inner.ids[id],D_005F7C30,&coords[1],self->a.time[id],(float)self->a.frame[id]);
  if(good[0] && good[1]) {
   mode=(int)(coords[0]+0.5f); int mode2=(int)(coords[1]+0.5f);
   good[0]=func_00394DC0(&self->a.out[0],&camera[0],offset,self->a.points[id],&self->a.positions[id],ctx,id,mode,0,self->a.angle[id]);
   good[1]=func_00394DC0(&self->a.out[1],&camera[1],offset,self->a.points[id],&self->a.positions[id],ctx,id,mode2,0,self->a.angle[id]);
   good[2]=func_00394DC0(&self->a.out[2],&camera[2],offset,self->a.points[id],&self->a.positions[id],ctx,id,mode,1,self->a.angle[id]);
  }
  if(!good[0] || !good[1] || !good[2]) self->a.ok=0;
 }
 self->a.okzoom=func_003EF708(player,&self->a.zoom,self->b.inner.ids[id],0,self->a.time[id],(float)self->a.frame[id]);
 if(self->a.ok && self->a.okzoom && mode==6) self->a.flag[id]=1;
 return result;
}
