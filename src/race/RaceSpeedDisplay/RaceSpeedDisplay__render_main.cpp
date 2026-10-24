/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
 char b0; unsigned char fx,fy; char b3;
 short x,y,w,h;
 float alpha; int p10; char *vt;
 unsigned int color,color2;
 char pad20[4]; float unitwidth;
 char pad28[0x46-0x28]; char unit[0x68-0x46];
 float speed,width;
};
struct Font { int a,mode; };
extern Font D_00585CC8;
extern char D_005F5600[];
extern int D_005865D0[];
extern "C" int func_0038F4A8(int,int,int);
extern "C" void func_0038F960(char *,float);
extern "C" void func_00415510(Font *,const char *);
extern "C" void func_00415578(Font *);
extern "C" float func_00415820(Font *);
extern "C" void func_00415A10(Font *,float,float,float);
extern "C" void func_00415B10(Font *,unsigned int);
extern "C" float func_00415C58(Font *,const char *);
extern "C" void func_00415CC0(Font *,const char *);
extern "C" void func_00415D18(Font *,const char *,...);
extern "C" char *func_004391C8(int *);
extern "C" float func_00439488(int *,float);
static inline float maxf(float a,float b) {float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r;}
extern "C" void RaceSpeedDisplay__render_main(Obj *o) {
 char buf[32];
 float zero=0.0f;
 Font *g=&D_00585CC8;
 func_00415B10(g,o->color);
 g->mode=2;
 float x=(float)func_0038F4A8(o->x,0,o->fx);
 float y=(float)o->y;
 func_00415A10(g,x,y,zero);
 const char *font=D_005F5600;
 func_00415510(g,font);
 int *conv=D_005865D0;
 const char *text=func_004391C8(conv);
 func_00415D18(g,text);
 float inv=1.0f/func_00415820(g);
 if(o->width==zero) o->width=func_00415C58(g,text)*inv;
 func_00415510(g,font);
 func_0038F960(buf,func_00439488(conv,o->speed));
 func_00415A10(g,x-o->width,y,zero);
 func_00415D18(g,buf);
 float extent=maxf(o->width+func_00415C58(g,buf)*inv,90.0f)+10.0f;
 func_00415510(g,font);
 if(o->unitwidth==zero) { text=o->unit; o->unitwidth=func_00415C58(g,text)*inv; }
 else text=o->unit;
 func_00415A10(g,x-extent-o->unitwidth,y,0.0f);
 func_00415B10(g,o->color2);
 func_00415CC0(g,text);
 g->mode=0;
 func_00415578(g);
}
