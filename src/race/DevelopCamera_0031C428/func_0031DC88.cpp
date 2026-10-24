/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char *vt; };
struct Tgt { char *vt; };
struct Entry { short delta,index; Tgt *(*fn)(void *,int); };
struct Out { int a,b; float c; };
extern "C" void func_003A7880(char *,int);
extern "C" int func_003A8A98(char *,char *,char *,int,int *);
extern "C" int func_003A8A20(char *,char *,int);
extern "C" void func_00320468(Obj *,char *,char *,int,unsigned,Out *);
extern "C" void func_00320538(Obj *,char *,char *,int,unsigned,Out *);
extern "C" void func_00320630(Obj *,char *,char *,int,unsigned,Out *);
extern "C" void func_0031FCB0(Obj *,char *,char *,int,unsigned,Out *,int);
extern "C" void func_00321B08(Tgt *,char *,char *,char *,char *);
extern "C" void func_0032E780(char *,float);
extern "C" float func_0032E850(char *);
static inline Tgt *get(Obj *self,int idx) {
    Entry *e=(Entry *)(self->vt+0xE0);
    return e->fn((char *)self+e->delta,idx);
}
extern "C" void func_0031DC88(Obj *self,char *ctx,char *other,int idx,unsigned flags,Out *out) {
    int buf[4];
    char *base=(char *)self+idx*0x1B4;
    char *p=base+0x10;
    char *fp=base+0xF8;
    float scale=1.0f;
    float value=0.0f;
    if (*(unsigned char *)(fp+0x1E)) value=scale;
    char *spring=base+0x164;
    func_0032E780(spring,value);
    float raw=func_0032E850(spring)*3.0f;
    float lo=scale;
    scale=raw+scale;
    if (scale<=lo) scale=lo;
    if (scale>=4.0f) scale=4.0f;
    int changed=0;
    if (*(unsigned char *)((char *)self+0xCE8) && *(int *)((char *)self+0xCF0)%900==0) {
        int count=**(int **)(ctx+0x60);
        int max=count-1;
        int next=*(int *)((char *)self+0xCEC)+1;
        next%=count;
        if (next<0) next=0;
        if (max<next) next=max;
        *(int *)((char *)self+0xCEC)=next;
        if (*(short *)(p+0xC)!=next) {
            changed=1;
            func_003A7880(p,next);
            out->c=0.5f;
        }
    }
    int next=*(int *)(p+0x1A4);
    if (next>=0 && *(short *)(p+0xC)!=next) {
        changed=1;
        func_003A7880(p,next);
    }
    signed char direction=*(signed char *)(fp+0x1F);
    if (direction!=0) {
        if (func_003A8A20(ctx,p,direction>0)) changed=1;
    }
    if (changed) {
        flags|=2;
        out->b=1;
    }
    switch (func_003A8A98(ctx,other,p,0,buf)) {
    case 1: func_00320468(self,ctx,other,idx,flags,out); break;
    case 2: func_00320538(self,ctx,other,idx,flags,out); break;
    case 3: func_00320630(self,ctx,other,idx,flags,out); break;
    default:
        if (get(self,idx)==*(Tgt **)(p+0x170)) flags|=2;
        func_0031FCB0(self,ctx,other,idx,flags,out,0);
        break;
    }
    Tgt *t=get(self,idx);
    *(float *)((char *)t+0x14C)=scale;
    func_00321B08(t,ctx,fp,p,(char *)self+0xA80);
}
