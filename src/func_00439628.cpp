/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { char pad[0x10]; int mode; };
extern "C" float func_004395C0(O *, float) throw();
static inline float scale(float x) { return x*0x1.3e26d4p-1f; }
extern "C" int func_00439628(O *o, float a, float b) {
 float fuel=func_004395C0(o,b);
 switch(o->mode) {
 
 case 1: b = scale(a); break;
 case 2: b = scale(a); break;
 case 3: {
  b=a;
  if(b < 0x1.0624dcp-10f) return 999;
  float v=fuel*1000000.0f/b;
  int r=(int)v;
  if(v>=999.0f) r=999;
  return r;
 }
 case 0: default: b=a; break;
 }
 if(b<0x1.47ae14p-7f) return 0;
 if(fuel<0x1.0c6f7ap-20f) return 999;
 float v=b*0x1.47ae14p-7f/fuel;
 if(v>999.0f) return 999;
 return (int)v;
}
