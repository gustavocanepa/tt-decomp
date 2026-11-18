struct Obj { unsigned char b0,xflag,yflag,b3; short x,y; int z; float alpha; void *tex; void *vt; void *bar,*mark; float amount,capacity; };
struct Text { int a,align; };
extern Text D_00585CC8;
extern char D_005F5600[],D_005F5628[];
extern "C" {
void func_0035AFF0(Obj *);
void func_0038E838(void *,int,int,float,float,float,float);
void func_0038EC28(void *,float,float,float,float,int,int);
float func_0038F448(int,float,float);
unsigned int func_0038F5F8(unsigned int,float);
void func_00477DC0(unsigned int);
void func_00477E30(float,float,float,float);
void func_00415510(Text *,const char *);
void func_00415578(Text *);
void func_00415A10(Text *,float,float,float);
void func_00415B10(Text *,unsigned int);
void func_00415D18(Text *,const char *,...);
}
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void RaceRefuelMeter__render_main(Obj *o) {
 if (!o->tex) func_0035AFF0(o);
 Text *t=&D_00585CC8;
 func_00477E30(1.0f,1.0f,1.0f,o->alpha);
 func_0038E838(o->tex,o->xflag,o->yflag,o->x,o->y,256.0f,26.0f);
 func_00477DC0(func_0038F5F8(0x805ea8f2,o->alpha));
 float x=func_0038F448(o->xflag,o->x,256.0f)+15.0f;
 float y=func_0038F448(o->yflag,o->y,26.0f);
 float w=minf(maxf(o->amount/o->capacity,0.0f),1.0f)*155.0f;
 func_0038EC28(o->bar,x,y,x+w,y+26.0f,0,0);
 func_00477E30(1.0f,1.0f,1.0f,o->alpha);
 float x2=func_0038F448(o->xflag,o->x,256.0f)+14.0f;
 float y2=func_0038F448(o->yflag,o->y,26.0f)+7.0f;
 float bottom=y2+12.0f;
 func_0038EC28(o->mark,x2,y2,x2+157.0f,bottom,0,0);
 func_00415510(t,D_005F5600);
 func_00415B10(t,func_0038F5F8(0x805ea8f2,o->alpha));
 t->align=2;
 func_00415A10(t,x2+227.0f,bottom-1.0f,0.0f);
 func_00415D18(t,D_005F5628,(int)(o->amount+0.5f),(int)(o->capacity+0.5f));
 t->align=0;
 func_00415578(t);
}
