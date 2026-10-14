/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Car { char pad0[0x14]; int id; char pad18[0x3444-0x18]; int pos; };
struct List { int count; int pad4; Car **cars; };
struct Group { char pad0[0x60]; List *list; };
struct Owner { int pad0; int *handle; char pad8[0x54]; int p5c; char pad60[0x10]; int x70; int x74; char pad78[0x18]; int flags; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_005A4C58;
extern char D_006A3500[], D_006A3350[];
extern "C" void func_0056BAF8();
extern "C" void func_00569F90();
extern "C" int func_003D8BE8(Owner *,Car *) throw();
extern "C" void func_003DA518(int *,int,const char *,int) throw();
extern "C" Found *func_004475D8(int,Str *);
extern "C" void func_004A45D0(void *) throw();
extern "C" int func_004A6500(char *,const char *,...) throw();
extern "C" u32 func_004A8368(const char *) throw();
extern "C" char *GT4MC__FileGT4GameData__loadInstance(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *func_00550E18(Str *,u32,u32,const char *,u32);
struct Val { int type; int spare[3]; };
extern char D_005F2A30[],D_005F2A38[],D_005F2A40[];
extern "C" int RaceMonitor__is_player_car(Owner *) throw();
extern "C" void RaceMonitor__update_pit_panel(Owner *,int) throw();
extern "C" void func_0043D510(Val *);
extern "C" void func_0043D738(Val *,const char *);
extern "C" int func_00447738(int,Str *,Val *);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_005A4C58); func_00550E18(s,0,-1,p,func_004A8368(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) func_004A45D0(r); }
extern "C" void func_002DA808(Owner *self) {
    char buf[64];
    Val value;
    Str s;
    int handle=*self->handle;
    Val *pv=&value;
    pv->type=1;
    buf[0]=0;
    if(self->p5c==0 || (((self->flags>>4)^1)&1)) func_004A6500(buf,D_005F2A30,self->x74);
    func_0043D738(pv,buf);
    Str *ps=&s;
    construct(ps,D_005F2A38);
    func_00447738(handle,ps,pv);
    destroy(ps);
    construct(ps,D_005F2A40);
    char *result=0;
    Found *found=func_004475D8(handle,ps);
    if(found) {
        Entry *e=found->entry;
        result=GT4MC__FileGT4GameData__loadInstance(e->fn,func_0056BAF8,0,(char *)found+e->delta,func_00569F90,found);
    }
    destroy(ps);
    if(result) *(int *)(result+0x74)=self->x70;
    RaceMonitor__update_pit_panel(self,RaceMonitor__is_player_car(self));
    func_0043D510(pv);
}
