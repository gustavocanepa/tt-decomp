/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len,cap,ref,selfish; };
struct Str { char *p; };
struct Val { int type; int spare[3]; };
struct Owner { int pad; int *handle; char pad8[8]; int race; char pad14[0x50]; int player; };
struct Entry { short delta,pad; void *fn; };
struct Found { char pad[0x5c]; Entry *entry; };
extern Rep D_005A4C58;
extern char D_005F2A00[],D_005F2A10[],D_005F28E8[],D_005F28B8[],D_005F2A20[],D_005F2A28[];
extern "C" void func_0056BAF8();
extern "C" void func_00569F90();
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *func_00550E18(Str *,u32,u32,const char *,u32);
extern "C" u32 func_004A8368(const char *) throw();
extern "C" void func_004A45D0(void *) throw();
extern "C" Found *func_004475D8(int,Str *);
extern "C" char *GT4MC__FileGT4GameData__loadInstance(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" int func_00305600(int,int,int,signed char *);
extern "C" int func_004A6500(char *,const char *,...);
extern "C" void func_0043D738(Val *,const char *);
extern "C" void func_0043D510(Val *);
extern "C" int func_00447738(char *,Str *,Val *);
extern "C" const char *func_0038FAE8(int);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_005A4C58); func_00550E18(s,0,-1,p,func_004A8368(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) func_004A45D0(r); }
extern "C" void RaceMonitor__update_pit_panel(Owner *self,int enabled) {
 union { Str str; signed char tires[2]; } u;
 char key[16];
 char buf[64];
 Val value;
 Str s;
 int handle=*self->handle;
 Str *ps0=&u.str;
 construct(ps0,D_005F2A00);
 char *panel=0;
 Found *f=func_004475D8(handle,&u.str);
 if(f) { Entry *e=f->entry; panel=GT4MC__FileGT4GameData__loadInstance(e->fn,func_0056BAF8,0,(char *)f+e->delta,func_00569F90,f); }
 destroy(&u.str);
 int count=0;
 if(panel) {
  *(int *)(panel+0x74)=enabled;
  for(int i=0;i<3;i++) count+=func_00305600(self->race,self->player,2-i,0)>0;
  for(int i=0;i<3;i++) {
   int next=i+1;
   Val *pv=&value; pv->type=1;
   func_004A6500(key,D_005F2A10,next);
   int lap=0;
   u.tires[0]=-1; u.tires[1]=-1;
   if(i<count) lap=func_00305600(self->race,self->player,count-i-1,u.tires);
   if(lap>0) { func_004A6500(buf,D_005F28E8,lap); func_0043D738(pv,buf); }
   else func_0043D738(pv,D_005F28B8);
   Str *ps=&s;
   construct(ps,key); func_00447738(panel,&s,pv); destroy(&s);
   func_004A6500(key,D_005F2A20,next);
   func_0043D738(pv,func_0038FAE8(u.tires[0]));
   construct(ps,key); func_00447738(panel,&s,pv); destroy(&s);
   func_004A6500(key,D_005F2A28,next);
   func_0043D738(pv,func_0038FAE8(u.tires[1]));
   construct(ps,key); func_00447738(panel,&s,pv); destroy(&s);
   func_0043D510(pv);
  }
 }
}
