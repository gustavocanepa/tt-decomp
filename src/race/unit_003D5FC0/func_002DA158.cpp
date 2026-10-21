/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Val { int type; int spare[3]; };
struct Owner { int pad0; int *handle; char pad8[0x4c-8]; int pace, p50, p54, p58; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_005A4C58;
extern char D_005F2960[], D_005F2970[], D_005F29E8[], D_005F29F0[];
extern int D_00621C78[];
extern "C" void func_0056BAF8();
extern "C" void func_00569F90();
extern "C" int func_002D7F98(Owner *) throw();
extern "C" void func_002D9150(int *,char *,const char *,int) throw();
extern "C" Found *func_004475D8(int,Str *);
extern "C" void free(void *) throw();
extern "C" void func_004A6500(char *,const char *,...);
extern "C" u32 func_004A8368(const char *) throw();
extern "C" char *GT4MC__FileGT4GameData__loadInstance(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *func_00550E18(Str *,u32,u32,const char *,u32);
extern "C" char *DisplayRText__getRTextStr(int);
extern "C" void func_0043D510(Val *);
extern "C" void func_0043D738(Val *,const char *);
extern "C" int func_00447738(char *,Str *,Val *);
static inline char *grab(Rep *r) { if(r->selfish) return strobe__toUpper(r); ++r->ref; return (char *)(r+1); }
static inline void construct(Str *s,const char *p) { s->p=grab(&D_005A4C58); func_00550E18(s,0,-1,p,func_004A8368(p)); }
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void func_002DA158(Owner *self) {
    union { Val v; Str s; } first;
    union { char buf[32]; Str s; } second;
    Str *ps=&first.s;
    int handle=*self->handle;
    const char *name=D_005F2960;
    ps->p=grab(&D_005A4C58);
    char *result=0;
    func_00550E18(ps,0,-1,name,func_004A8368(name));
    Found *found=func_004475D8(handle,&first.s);
    if(found) {
        Entry *e=found->entry;
        result=GT4MC__FileGT4GameData__loadInstance(e->fn,func_0056BAF8,0,(char *)found+e->delta,func_00569F90,found);
    }
    destroy(&first.s);
    if(result) *(int *)(result+0x74)=func_002D7F98(self);
    for(int i=1;i<8;i++) {
        func_004A6500(second.buf,D_005F2970,i);
        int flag=0;
        switch(i) {
        case 1: case 2: case 3: case 4: case 5: flag=i==self->pace+1; break;
        case 6: flag=self->p50>0; break;
        case 7: flag=self->p54>0; break;
        }
        func_002D9150(self->handle,result,second.buf,flag);
    }
    const char *text=DisplayRText__getRTextStr(((int *)0x582A88)[self->p58]);
    if(!text) text=D_005F29E8;
    first.v.type=1;
    func_0043D738(&first.v,text);
    construct(&second.s,D_005F29F0);
    func_00447738(result,&second.s,&first.v);
    destroy(&second.s);
    func_0043D510(&first.v);
}
