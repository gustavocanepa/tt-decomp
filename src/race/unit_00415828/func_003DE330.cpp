/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct __attribute__((aligned(16))) Vec {
 union { u128 bits; struct {float x,y,z,w;}; };
 Vec() {} Vec(const Vec &v) {bits=v.bits;} Vec(float a,float b,float c) { x=a;y=b;z=c; }
 void multiply(float f) {x*=f;y*=f;z*=f;}
 Vec operator*(float f) const { Vec v(*this); v.multiply(f); return v; }
 Vec &operator=(const Vec &v) {bits=v.bits;return *this;}
};
extern Vec D_00585370;
extern "C" void func_003E7FC8(Vec*,Vec*,Vec*,Vec*);
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
extern "C" int func_003DE330(float *outx,float *outy,float ax,float ay,float az,float bx,float by,float bz,float cx,float cy,float cz) {
 Vec delta(cx-ax,cy-ay,cz-az);
 Vec direction(bx,by,bz);
 int result=0;
 float squared=delta.x*delta.x+delta.y*delta.y+delta.z*delta.z;
 if(squared<0.0001f) return result;
 {
  float length; asm("sqrt.s %0, %1":"=f"(length):"f"(squared));
  delta=delta*(1.0f/length);
  Vec angles; float &anglevalue=angles.x;
  func_003E7FC8(&angles,&delta,&D_00585370,&direction);
  Vec angle; float &value=angle.x;
  value=anglevalue;
  *outx=length*func_004A5D18(value);
  value=anglevalue;
  *outy=length*func_004A5C50(value);
  return 1;
 }
 return result;
}
