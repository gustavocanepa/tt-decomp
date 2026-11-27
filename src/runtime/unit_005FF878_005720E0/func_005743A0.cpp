/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned int u32; typedef long s64; typedef short s16; typedef unsigned short u16; typedef unsigned char u8;
#define F(p,t,o) (*(t*)((char*)(p)+(o)))
struct Request { char p0[0x14]; int m14; char p18[12]; int m24; char p28[8]; int flags; char p34[12]; };
struct Tone { u8 a,b,c,d,flags; char p5[8]; u8 v; char pE[2]; };
struct Owner { char p0[8]; s64 id; int key; s16 x,y; char p18[12]; int f24; char p28[8]; void *p30; };
extern s64 D_006137B0;
extern "C" void *func_004C43C8(void*,u32);
extern "C" void func_004C5318(Owner*,void*,int,int,int,void*,Tone*);
extern "C" int func_004C7A48(Request*,s64);
extern "C" void *func_004C7B10(Request*,int);
extern "C" void *func_004C7C20(Request*);
extern "C" void func_004C8188(void*,int);
extern "C" void func_004C81C8(void*,int);
extern "C" void func_004C8920(void*,int);
extern "C" void func_005743A0(Owner *self,int index,int note,int arg3) {
    Request req;
    void *prog=func_004C43C8(self->p30,index);
    if(!prog) return;
    Tone *tone=(Tone*)((char*)prog+8);
    if(!tone) return;
    int delta=note-F(prog,u8,6);
    if(delta<0) return;
    int key=self->key;
    tone+=delta;
    void *voice=0;
    int value,selector;
    if(key!=-1) {
        selector=key;
        func_004C7A48(&req,self->id);
        voice=func_004C7B10(&req,selector);
        if(voice) { value=0; goto setup; }
        goto done;
    } else {
        value=tone->a;
        selector=tone->b;
        if(value) {
            func_004C7A48(&req,D_006137B0);
            req.flags|=32;
            req.m24=value;
            voice=func_004C7C20(&req);
        }
        if(!voice) {
            func_004C7A48(&req,self->id);
            req.flags|=2;
            req.m14=4;
            voice=func_004C7C20(&req);
            if(!voice) goto done;
        }
    }
setup:
    {
    F(voice,int,0x30)=2;
    F(voice,int,0x40)=value;
    F(voice,int,0x34)=selector;
    int field=F(self->p30,int,0x10);
    F(voice,u8,0x1f)=1;
    F(voice,int,0x50)=field;
    int x=self->x,y=self->y;
    F(voice,s16,0x64)=x;
    F(voice,s16,0x66)=y;
    F(voice,int,0x70)=tone->v;
    if((tone->flags&128) || self->f24) F(voice,u8,0x25)=1;
    if(tone->flags&32) {func_004C81C8(voice,10); func_004C8188(voice,127);}
    if(tone->flags&2) {func_004C8920(voice,tone->c); F(voice,u8,0x26)=1;}
    if(self->key!=-1) { if((u8)(tone->flags&1)) F(voice,u16,0x1a)|=4; }
    func_004C5318(self,voice,index,note,arg3,prog,tone);
    }
done:;
}
