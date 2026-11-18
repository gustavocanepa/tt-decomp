/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
struct VEntry { s16 delta,index; void *(*fn)(void *,s32); };
struct VFEntry { s16 delta,index; f32 (*fn)(void *); };
extern "C" s32 func_0031F150(void *,s32,void *,void *,s32) throw();
extern "C" void func_00321B08(void *,void *,void *,void *,void *);
extern "C" void func_003A7880(void *,s32);
extern "C" s32 func_003A8140(void *,s32);
extern "C" s32 func_003A8A98(void *,s32,void *,s32,s32 *);
extern "C" void func_003ABC78(void *,s32);
extern "C" s32 func_003AC030(void *);
extern "C" s32 func_003AC048(void *);
extern "C" f32 func_005357F8(void *);
extern "C" void func_0031F610(char *arg0,void *arg1,s32 arg2,s32 arg3,s32 flags,char *out) {
    s32 scratch;
    char *s7=arg0+0xC40;
    char *s=arg0+arg3*0x1B4;
    char *fp=arg0+4;
    char *p2=s+0xF8;
    char *sel=s+0x10;
    s32 reset=func_003AC030(s7)!=0;
    if(F(p2,s32,0x10)&0x10) reset=1;
    if(reset) {
        s32 n=F(arg0,s32,0xB8C);
        s32 active=func_003AC048(s7);
        s32 eligible=(n<120)==0;
        if(!active) eligible=0;
        flags|=2;
        if(eligible) {
            s16 old=F(sel,s16,0xC);
            s32 count=*F(arg1,s32 *,0x60);
            s32 i=(s32)(func_005357F8(fp)*(f32)count);
            count--;
            if(i<=0) i=0;
            if(i>=count) i=count;
            func_003A7880(sel,func_003A8140(arg1,i));
            if(F(sel,s16,0xC)!=old) F(out,s32,4)=1;
        }
    }
    s32 pending=F(sel,s32,0x1A4);
    if(pending>=0) {
        flags|=2;
        func_003A7880(sel,pending);
        F(out,s32,4)=1;
    }
    func_003ABC78(arg0+0xC80,reset);
    s32 status=func_003A8A98(arg1,arg2,sel,0,&scratch);
    if(status==1 || status==3) flags|=2;
    if((flags&2) && func_0031F150(arg0,arg3,arg1,sel,arg2)) {
        F(out,s32,0)=1;
        F(s7,f32,0x20)=0.0f;
        if(func_005357F8(fp)<0.1f) F(s7,f32,0x20)=func_005357F8(fp)*0.5f+0.5f;
    }
    VEntry *e=(VEntry *)(F(arg0,char *,0)+0xE0);
    func_00321B08(e->fn(arg0+e->delta,arg3),arg1,p2,sel,arg0+0xA80);
    F(out,f32,0xC)=F(s7,f32,0x20);
    VEntry * e_2 = (VEntry *)(F(arg0,char *,0)+0xE0);
    char *o=(char *)e_2->fn(arg0+e_2->delta,arg3);
    VFEntry *ef=(VFEntry *)(F(o,char *,0)+0xD8);
    f32 f=ef->fn(o+ef->delta);
    if(f>0.0f) F(out,f32,0xC)=f;
}
