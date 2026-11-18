/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0x70];float level;char pad74[0x264];int dirty; };
static inline float maxf(float a,float b) {float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline float minf(float a,float b) {float r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline float clamp(const float &v,float lo,float hi) {return minf(maxf(v,lo),hi);}
extern "C" Obj *func_003DFAB8(Obj *o) {
 struct Temps { volatile float lo,hi;float v; } temps;
 float v=0x1.666666p-2f;
 temps.lo=0.0f;
 temps.hi=1.0f;
 float l=temps.lo,h=temps.hi;
 temps.v=v;
 float r=clamp(temps.v,l,h);
 o->dirty=1;
 o->level=r;
 return o;
}
