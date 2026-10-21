/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
struct Vec { float x,y,z; };
static inline float radians(float a) { return a*0x1.921fb4p+1f/180.0f; }
extern "C" void func_0034E690(Vec *o, float a, float b) {
 float yaw=b;
 float pitch=-a;
 float sn=func_004A5D18(radians(pitch));
 float cs=func_004A5C50(radians(pitch));
 sn=-sn;
 yaw=-yaw;
 float x=func_004A5D18(radians(yaw));
 float z=func_004A5C50(radians(yaw));
 o->x=x*cs; o->y=sn; o->z=z*cs;
}
