/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x,y,z; Vec3(float a,float b,float c):x(a),y(b),z(c){} };
struct Probe {
 float x,z,y; int id; float height; char pad14[0x1c];
 unsigned char miss,pad31,kind,flags; char pad34[12];
 Probe(Vec3 v):x(v.x),z(v.z),y(-v.y){}
};
extern "C" void func_0034B3E0(void *,Probe *);
extern "C" int func_002E90E0(Probe *);
extern "C" float func_00436A68(void *,float,float,float,int *,int *);
extern "C" float func_004A5B78(float,float);
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
static inline void set(float *p,float x) { *p=x; }
extern "C" int func_00436AE0(void *c,float *height,float *pitch,float *roll,int *kind,int *material,int *flag,int key,float x,float y,float z,float angle) {
 int miss[4]; int k=key;
 Probe p(Vec3(x,y,z)); p.id=k;
 func_0034B3E0(c,&p);
 k=p.id;
 set(roll,0.0f); set(pitch,0.0f);
 float h;
 if(p.miss==0) {
  h=p.height; *height=h; *flag=p.flags&1;
  *kind=func_002E90E0(&p); *material=p.kind;
 } else {
  set(height,0.0f); *flag=0; *kind=0; *material=0; return 0;
 }
 float dx=func_004A5D18(angle)*0.5f;
 float dy=func_004A5C50(angle)*0.5f;
 float a=func_00436A68(c,x-dx,y+dy,z,&k,&miss[0]);
 float b=func_00436A68(c,x+dx,y-dy,z,&k,&miss[1]);
 float d=func_00436A68(c,x-dy,y-dx,z,&k,&miss[2]);
 float e=func_00436A68(c,x+dy,y+dx,z,&k,&miss[3]);
 if(miss[0] && miss[1]) return 0;
 if(miss[2] && miss[3]) return 0;
 if(miss[0]) *pitch=func_004A5B78(h-b,0.5f);
 else if(miss[1]) *pitch=func_004A5B78(a-h,0.5f);
 else *pitch=func_004A5B78(a-b,1.0f);
 if(miss[2]) *roll=func_004A5B78(h-e,0.5f);
 else if(miss[3]) *roll=func_004A5B78(d-h,0.5f);
 else *roll=func_004A5B78(d-e,1.0f);
 return 1;
}
