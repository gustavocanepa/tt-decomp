/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { float value,time,cycle,duty,rise,fall; int count; unsigned char waveform; };
static inline float maxf(float a,float b) { __asm__("max.s %0, %1, %0":"+f"(b):"f"(a)); return b; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void Oscillator__update(Obj *o,float dt) {
 int count=o->count;
 int active;
 if (count!=0) {
  float cycle=o->cycle;
  float time=o->time+dt;
  o->time=time;
  if (cycle<time) {
   o->time=time-(float)(int)(time/cycle)*cycle;
   if (count>0) o->count=count-1;
  }
  active=o->time<o->duty*cycle;
 } else active=o->waveform;
 float rate;
 if (active!=0) rate=o->rise;
 else rate=-o->fall;
 o->value=minf(maxf(o->value+dt*rate,0.0f),1.0f);
}
