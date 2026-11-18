/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { unsigned char p0,fx,fy,p3; short x,y,w,h; float alpha; char p10[8]; int laps,count,rows; int times[8]; float spacing; };
struct Font { int p0,flags; char p8[32]; float scale; };
extern Font D_00585CC8;
extern char D_005F5600[],D_005F5608[];
extern "C" {
float RaceDisplayUtil__wideOffset(int);
unsigned func_0038F5F8(unsigned,float);
void RaceDisplayUtil__timeToString(char *,int);
void func_00415510(void *,void *);
void func_00415578(void *);
float func_00415820(void *);
void func_00415A10(void *,float,float,float);
void func_00415B10(void *,unsigned);
float func_00415C58(void *,void *);
void func_00415CC0(void *,void *);
void func_00415D18(void *,const char *,int);
int func_00416078(void *);
}
static inline float maxf(float a,float b) { float r; __asm__("max.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void RaceLapTimesDisplay__render_main(Self *s) {
 D_00585CC8.flags=2;
 float width=90.0f;
 func_00415B10(&D_00585CC8,func_0038F5F8(0x80c8c8c8,s->alpha));
 func_00415510(&D_00585CC8,D_005F5600);
 float spacing=(float)func_00416078(&D_00585CC8)*s->spacing;
 int start=s->count-s->rows; if(start<0) start=0;
 float scale=1.0f/func_00415820(&D_00585CC8);
 float y=(float)s->x;
 float x=y+RaceDisplayUtil__wideOffset(s->fx);
 y=(float)s->y;
 char buf[16];
 for (int i=start;i<start+s->rows;i++) {
  int t=-1; if(i<s->count) t=s->times[i];
  RaceDisplayUtil__timeToString(buf,t);
  float w=func_00415C58(&D_00585CC8,buf);
  width=maxf(width,w);
  if(i<s->count) {
   func_00415A10(&D_00585CC8,x-w*scale,y,0.0f);
   func_00415CC0(&D_00585CC8,buf);
   y+=spacing;
  }
 }
 func_00415B10(&D_00585CC8,func_0038F5F8(0x80b3b3b3,s->alpha));
 func_00415510(&D_00585CC8,D_005F5600);
 int start2=s->laps-s->rows; if(start2<=0) start2=0;
 y=(float)s->y;
 width=(width+10.0f)*D_00585CC8.scale;
 x-=width;
 for(int i=start2;i<start2+s->rows;i++) {
  if(i<s->laps) {
   func_00415A10(&D_00585CC8,x,y,0.0f);
   func_00415D18(&D_00585CC8,D_005F5608,i+1);
   y+=spacing;
  }
 }
 D_00585CC8.flags=0;
 func_00415578(&D_00585CC8);
}
