/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
void func_003BC998(int *,int);
float func_003BCC20(void *);
float func_003BCCC0(void *);
float func_003BCD00(void *);
float func_003BCCC8(void *);
float func_003BCD08(void *);
float func_003BCD40(void *);
float func_003BCD48(void *);
float func_003BCFE0(void *);
float *func_003BD070(int *);
float *func_003BD100(int *);
float *func_003BD120(int *);
float *func_003BD110(int *);
float *func_003BD130(int *);
float *func_003BD140(int *);
float *func_003BD150(int *);
float *func_003BD380(int *);
int func_003E6F48(float);
}
static inline float maxf(float x,float y) { float r; asm("max.s %0,%1,%2":"=f"(r):"f"(x),"f"(y)); return r; }
static inline float minf(float x,float y) { float r; asm("min.s %0,%1,%2":"=f"(r):"f"(x),"f"(y)); return r; }
static inline float clamp(float x) {return minf(maxf(x,0.0f),1.0f);}
static inline float clampref(float v) { float r; asm("max.s %0,%1,%2":"=f"(r):"f"(v),"f"(0.0f):"memory"); asm("min.s %0,%1,%2":"=f"(r):"f"(r),"f"(1.0f)); return r; }
extern "C" void func_003C1488(char *self,int arg,float t) {
 struct { int h; float x; } sp;
 char *a=self+0x310;
 func_003BC998(&sp.h,arg);
 char *b=self+0x450;
 float x=clamp(func_003BCC20(a));
 float y=clamp(func_003BCC20(b));
 if(y-x>0.8f) {
  y=y*t+(x+1.0f)*(1.0f-t);
  y=y-(float)func_003E6F48(y);
  *func_003BD070(&sp.h)=y;
 }
 float v=func_003BCCC0(a);
 if(v==func_003BCD00(a)) {
  v=func_003BCCC0(b);
  if(v!=func_003BCD00(b)) {
   float *p=func_003BD100(&sp.h); *p=func_003BCCC0(b);
   p=func_003BD120(&sp.h); *p=func_003BCD00(a);
   clamp(func_003BCD40(a));
   sp.x=clamp(func_003BCD40(b))*t+(1.0f-t);
   sp.x=clampref(sp.x);
   *func_003BD140(&sp.h)=sp.x;
  }
 }
 v=func_003BCCC8(a);
 if(v==func_003BCD08(a)) {
  v=func_003BCCC8(b);
  if(v!=func_003BCD08(b)) {
   float *p=func_003BD110(&sp.h); *p=func_003BCCC8(b);
   p=func_003BD130(&sp.h); *p=func_003BCD08(a);
   clamp(func_003BCD48(a));
   sp.x=clamp(func_003BCD48(b))*t+(1.0f-t);
   sp.x=clampref(sp.x);
   *func_003BD150(&sp.h)=sp.x;
  }
 }
 float z=func_003BCFE0(b);
 float w=func_003BCFE0(a);
 int iz=(int)z;
 if(z-w>0.5f || w-z>0.5f) {
  float iw=(float)(int)w;
  z=z*t+((float)iz+(w-iw))*(1.0f-t);
  int n=(int)z;
  if(n==iz) *func_003BD380(&sp.h)=z;
  else *func_003BD380(&sp.h)=iw+(z-(float)n);
 }
}
