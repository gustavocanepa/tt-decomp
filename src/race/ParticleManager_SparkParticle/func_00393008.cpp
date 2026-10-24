/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x,y,z,pad; };
struct P3 { float x,y,z; };
struct V4 { float x,y,z,w; };
struct T { char pad[116]; };
struct Manager { char pad[12]; T table[8]; };
struct Input { char pad[8]; P3 pos; float angle, size; V4 dir; char pad2[8]; float a,b; };
extern "C" void *func_003935B8(Manager *);
extern "C" void func_003CD910(void *, V3 *, V3 *, V3 *, V4 *, float, T *);
extern "C" float pglmRandom();
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
static inline float rsqrt(float n, float v) { float r=v; __asm__("rsqrt.s %0, %1, %0" : "+f"(r) : "f"(n)); return r; }
extern "C" void func_00393008(Manager *m, Input *p, V3 *v) {
 V3 velocity, position, rotation;
 float sign;
 float speed=(p->b-p->a)*(pglmRandom()*0x1.ccccccp-2f+0.5f);
 sign=speed;
 float angle, sn, cs, y, x, tilt, ts;
 if(speed<0.0f) speed=-speed;
 if(speed<2.0f) return;
 int count=0;
 do {
  void *s=func_003935B8(m);
  if(!s) return;
  angle=p->angle+pglmRandom()*0x1.0c1512p-1f+-0x1.0c1512p-2f;
  sn=func_004A5C50(angle);
  cs=func_004A5D18(angle);
  x=p->dir.x*cs+p->dir.z*sn;
  y=p->dir.y;
  float d=x*x+y*y;
  float k=rsqrt(1.0f,d);
  x=x*k;
  y=y*k;
  tilt=pglmRandom()*0x1.657160p-3f+-0x1.7bc884p+0f;
  if(sign<0.0f) tilt=-tilt;
  count++;
  ts=func_004A5C50(tilt);
  float tc=func_004A5D18(tilt);
  float t=ts*x-tc*y;
  velocity.x=t*cs*speed+v->x*0x1.b33332p-1f;
  velocity.y=(tc*x+ts*y)*speed+v->y*0x1.b33332p-1f;
  velocity.z=t*sn*speed+v->z*0x1.b33332p-1f;
  position.x=p->pos.x+(pglmRandom()-0.5f)*0x1.999998p-3f;
  position.y=p->pos.y+(pglmRandom()-0.5f)*0x1.999998p-3f;
  position.z=p->pos.z+(pglmRandom()-0.5f)*0x1.999998p-3f;
  rotation.x=(pglmRandom()-0.5f)*20.0f;
  rotation.y=(pglmRandom()-0.5f)*8.0f;
  rotation.z=(pglmRandom()-0.5f)*20.0f;
  int n=(int)(pglmRandom()*8.0f);
  if(n>=8)n=7;
  func_003CD910(s,&position,&velocity,&rotation,&p->dir,p->size,&m->table[n]);
 } while(count<=0);
}
