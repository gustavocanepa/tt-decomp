/* Picks a random trackside camera spot ahead of the car (replay/TV camera placement, inferred from the camera matrix
 * calls at the end and the 'dist'/'range' fields it fills): samples the track a few seconds ahead of the car, offsets it sideways
 * by 2 to 7 units, drops it onto the ground with a ray cast, and aims the camera back at the car with a small random tilt.
 * Returns non-zero when the spot is usable (track query succeeded, ground found, car inside half the view range). */
struct V { float x,y,z; float &X() { return x; } float &Y() { return y; } float &Z() { return z; } };
struct Obj { char pad[8]; float dist,range; char pad10[0x18]; V trans, angles; char pad40[0x140]; void *rng; void *scene; };
extern "C" {
float func_002E5DC8(void *);
float func_002E5DF0(void *);
float func_002E5E18(void *);
float func_002E5E40(void *,float);
float func_002E5EA0(void *,float);
float func_002E5ED0(void *,float);
float func_003173F8(void *) throw();
float func_003F3708(void *);
float func_003F3720(void *);
float func_003F3738(void *);
void func_003FCE70(void *);
void func_003FCEA8(void *,void *,void *,float);
float func_003A97E0(void *,void *,int *);
int func_003A9C38(void *,void *,void *,void *,int *,float);
void func_0046E150();
void func_0046E1B0();
void func_00473050();
void func_004730A8();
void func_004751FC();
void func_004752F8(void *);
void func_004755EC(float,float,float);
void func_00475730(float);
void func_00475758(float);
void func_00475780(float);
float func_005357F8(void *);
float func_00552A38(void *);
void func_00552A68(void *,void *);
void func_00552C90(void *,void *);
}
static inline float absf(float x) { float r; asm("abs.s %0,%1":"=f"(r):"f"(x)); return r; }
static inline float sqr(float x) { float r; asm("sqrt.s %0,%1":"=f"(r):"f"(x)); return r; }
static inline void set(V *p,float x,float y,float z) {p->x=x;p->y=y;p->z=z;}
static inline float *data(V *v) {return &v->x;}
extern "C" void *func_004F6678(void *,int,unsigned);
static inline void clear(V *v) {func_004F6678(v,0,sizeof(V));}
static inline void copy(V *out,V *in) {func_00552A68(&in->x,&out->x);}
extern "C" float func_002E5E70(void *,float);
extern "C" int func_002F0858(void *,unsigned,int,void *,float);
extern "C" float func_003174F8(float,float) throw();
extern "C" int func_003A7F60(void *,void *);
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
extern "C" void *func_004F6678(void *,int,unsigned);
extern "C" void func_00552C58(void *,void *);
static inline int negative(int n) { if(n<0) return 1; return 0; }
extern "C" int func_0032B590(Obj *self,void *car,void *track,float lookAheadSeconds) {
 V pos,rot,origin,dir,tmp,a,b,off,start,hit;
 int id;
 V *carPosPtr=&dir,*scratchPtr=&tmp;
 V *rotPtr=&rot;
 void *rng=self->rng;
 clear(&pos);
 clear(&rot);
 float factor=lookAheadSeconds*(func_005357F8(rng)*0.35f+0.5f);
 float x=func_002E5E40(car,0.0f);
 float y=func_002E5EA0(car,0.0f);
 float z=func_002E5ED0(car,0.0f);
 origin.x=x;origin.y=y;origin.z=z;
 copy(carPosPtr,&origin);
 float tx=func_002E5DC8(car);
 float ty=func_002E5DF0(car);
 float tz=func_002E5E18(car);
 scratchPtr->X()=tx; scratchPtr->Y()=ty;scratchPtr->Z()=tz;
 func_00552C90(carPosPtr,scratchPtr);
 float base=func_002E5E70(car,0.0f);
 float speed=base-func_002E5E70(car,1.0f);
 float rangeRandom=func_005357F8(rng);
 float advance=speed*factor*60.0f;
 float range=rangeRandom*30.0f+50.0f;
 float aheadPos=base+advance;
 float aheadPosBehind=aheadPos-1.0f;
 clear(scratchPtr);
 int bad=negative(func_002F0858(track,6,0,&a,aheadPos));
 int ok=!bad;
 if(func_002F0858(track,6,0,&b,aheadPosBehind)<0)ok=false;
 float dist=100.0f;
 float *ry,*rz;
 if(ok) {
  V *sideOffset=&off;
  float dx=b.x-a.x,dy=b.y-a.y,dz=b.z-a.z;
  scratchPtr->X()=dx;scratchPtr->Y()=dy;scratchPtr->Z()=dz;
  float angle=func_003173F8(scratchPtr);
  dist=sqr(func_00552A38(scratchPtr));
  float shift=func_005357F8(rng)*5.0f+2.0f;
  if(func_005357F8(rng)<0.5f)shift=-shift;
  set(&pos,a.x,a.y,a.z);
  float sx=-func_004A5D18(angle);
  float sz=func_004A5C50(angle)*shift;
  set(sideOffset,sx*shift,0.0f,sz);
  func_00552C58(&pos,sideOffset);
  void *scene=self->scene;
  V *rayStartPtr=&start,*rayHitPtr=&hit;
  set(rayStartPtr,a.x,a.y,a.z);
  id=func_003A7F60(scene,rayStartPtr);
  if(id<0) ok=false;
  else {
   func_003A9C38(scene,rayStartPtr,&pos,rayHitPtr,&id,1.2f);
   id=-1;
   float ground=func_003A97E0(scene,rayHitPtr,&id);
   if(id<0) ok=false;
   else {
    float *hy=&hit.Y();
    float h=ground+0x1.999998p-4f;
    *hy=h+func_005357F8(rng)*0x1.333332p-1f;
    func_00552A68(rayHitPtr,&pos);
   }
  }
  ry=&rot.y;
  *ry=func_005357F8(rng)*20.0f-15.0f;
  rotPtr->x=angle+func_005357F8(rng)*20.0f-10.0f;
  rz=&rot.z;
  *rz=func_005357F8(rng)*30.0f-15.0f;
 }
 else {ry=&rot.y;rz=&rot.z;}
 copy(scratchPtr,&origin);
 func_00552C90(scratchPtr,&pos);
 float diff=absf(func_003174F8(func_003173F8(scratchPtr),rotPtr->x));
 if(diff>range*0.5f)ok=false;
 self->dist=dist;self->range=range;
 func_00552A68(&pos,(char*)self+0x190);
 func_0046E150();func_00473050();func_004751FC();
 func_00475780(*rz);func_00475730(*ry);func_00475758(rotPtr->x);
 func_004755EC(-pos.x,-pos.y,-pos.z);
 func_004752F8((char*)self+0x100);func_004730A8();func_0046E1B0();
 return ok;
}
