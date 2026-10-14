/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[12]; float angle; };
extern "C" float func_004A5DE0(float);
extern "C" void func_00321AF8(void *,float,float,float);
extern "C" void func_003AC158(Obj *o) {
 float *p=&o->angle;
 float t;
 float half;
 float rad;
 float one=1.0f;
 float x=*p;
 if(x<45.0f) x=45.0f;
 half=0.5f;
 rad=0x1.1df468p-6f;
 t=(one/func_004A5DE0(x*half*rad))*0x1.66819ap-1f;
 func_00321AF8(o,t,one,one/func_004A5DE0(*p*half*rad));
}
