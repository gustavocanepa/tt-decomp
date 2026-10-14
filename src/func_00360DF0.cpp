/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { char pad[0x20]; unsigned long size; };
struct Tex { char pad[0x18]; Image *image; };
struct Meter { char pad[0x18]; Tex *tex,*accel,*brake,*asmtex,*tcs,*grip; float a,b,c,d,e; unsigned color; signed char mode1,mode2; char pad4a[2]; float osc; char pad50[0x1c]; int flags; };
struct Buffer { int id,field4; };
extern "C" {
void func_00104A48(Buffer *,int,int);
int func_00104B10(Buffer *);
void func_00104C88(Buffer *);
void Oscillator__setCount(void *,int,unsigned char) throw();
void RaceMTRMeter__init_texset(Meter *);
void func_00361320(Meter *,Tex *,float,float,float,float,float,float,int);
void func_0038E838(Tex *,float,float,float,float,int,int);
void func_0038EA20(Tex *,float,float,unsigned,unsigned,int,int);
void func_0038EC28(Tex *,float,float,float,float,int,int);
unsigned RaceDisplayUtil__getScaledColor(unsigned,float,float);
int func_00467728(Tex *);
void func_0046AC48(Image *);
void func_0046F0F8(int);
void func_00470220(int,float);
void func_00470298(int);
void func_004702D8(int,float);
void func_00470450(int);
void func_00470478(int);
void func_00470B48(int);
void func_00470E60(int);
void func_00473178(int);
void func_00473050();
void func_004730A8();
void pglPushAttrib(int);
void func_00473498();
void func_004738A0(float,float,float,float,float,float);
void func_004751FC();
void func_00477DC0(unsigned);
void func_00478C98(int);
}
static inline float mn(float a,float b) { float r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float mx(float a,float b) { float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float oscValue(float *p) { return *p; }
extern "C" void RaceMTRMeter__render_buffer(Meter *m,Buffer *buf) {
 pglPushAttrib(1); RaceMTRMeter__init_texset(m);
 unsigned long bits=m->tex->image->size;
 int w=((bits>>14)&1023)+1;
 int h=((bits>>34)&1023)+1;
 if(buf->id==-1) { func_00104A48(buf,w,h); buf->field4=0; func_00104B10(buf); }
 func_00104C88(buf); func_00470450(-1); func_00470B48(0); func_00470E60(1);
 float fw=w;
 func_00477DC0(0x80ffffff); func_0046F0F8(6); func_00478C98(15); func_00478C98(4); func_00478C98(5);
 float fh=h;
 func_00470478(0); func_004702D8(0x44,0.0f);
 float cx=fw*0.5f, cy=fh*0.5f;
 func_00473178(1); func_00473050(); func_004751FC(); func_004738A0(0,fw,fh,0,-1,1);
 func_00473178(0); func_00473050(); func_004751FC(); func_0038EC28(m->tex,0,0,fw,fh,0,0); func_00470450(0xffffff);
 float base,end1,end2;
 
 if((m->flags&1)==0) {base=0;end1=m->b*60;end2=m->a*60;} else {base=180;end1=180-m->b*60;end2=180-m->a*60;}
 func_00477DC0(0x80808080); func_00361320(m,m->accel,cx,cy,45.25f,65,base,end2,16);
 func_00477DC0(0x80ffffff); func_00361320(m,m->accel,cx,cy,45.25f,65,base,end1,16);
 
 if((m->flags&1)==0) {end1=mn(m->c,m->d)*-60;end2=mx(m->c,m->d)*-60;base=0;} else {base=180;end1=mn(m->c,m->d)*60+base;end2=mx(m->c,m->d)*60+base;}
 func_00477DC0(0x80808080); func_00361320(m,m->brake,cx,cy,23.5f,42.5f,base,end2,16);
 func_00477DC0(0x80ffffff); func_00361320(m,m->brake,cx,cy,23.5f,42.5f,base,end1,16);
 func_00477DC0(m->color|0x80000000); func_00467728(m->grip); func_0046AC48(m->grip->image);
 float r=m->e*46; func_0038E838(m->grip,cx,cy,r,r,2,2);
 func_004702D8(0x44,0); func_0046F0F8(4); func_00470220(6,0.5f); func_00470298(0); func_00470450(-1);
 float *osc=&m->osc;
 float value=oscValue(osc);
 float values[3]; values[0]=0; values[1]=1; values[2]=value;
 if(m->mode1==2||m->mode2==2) Oscillator__setCount(osc,1,0);
 func_00477DC0(RaceDisplayUtil__getScaledColor(0x800099ff,values[m->mode1],1)); func_0038EA20(m->asmtex,0,fh,0,1,0,0);
 func_00477DC0(RaceDisplayUtil__getScaledColor(0x800000c8,values[m->mode2],1)); func_0038EA20(m->tcs,0,0,0,0,0,0);
 func_00478C98(4); func_004730A8(); func_00473178(1); func_004730A8(); func_00473178(0); func_00473498();
}
