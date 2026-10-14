/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; float &X() { return x; } float &Y() { return y; } float &Z() { return z; } };
struct Obj { char p[8]; float distance,range; char q[0x170]; void *rng; void *course; };
extern "C" {
float func_002E5DC8(void *); float func_002E5DF0(void *); float func_002E5E18(void *);
float func_002E5E40(void *,float); float func_002E5EA0(void *,float); float func_002E5ED0(void *,float);
int func_002F0858(void *,int,int,Vec *,float);
float func_003173F8(Vec *) throw();
float func_0034B268(void *,void *);
int func_003A7F60(void *,Vec *);
float func_003A97E0(void *,Vec *,int *);
int func_003A9C38(void *,Vec *,Vec *,Vec *,int *,float);
void func_0046E150(); void func_0046E1B0(); void func_00473050(); void func_004730A8(); void func_004751FC();
void func_004752F8(void *); void func_004755EC(float,float,float); void func_00475730(float); void func_00475758(float); void func_00475780(float);
float func_005357F8(void *); float func_00552A38(Vec *);
void func_00552A68(Vec *,Vec *); void func_00552C58(Vec *,Vec *); void func_00552C90(Vec *,Vec *);
}
static inline void set(Vec *v,float x,float y,float z) { v->X()=x; v->Y()=y; v->Z()=z; }
static inline void scale(Vec *v,float f) { v->X()*=f; v->Y()*=f; v->Z()*=f; }
extern "C" int func_0032B128(Obj *self,void *car,void *path,float factor) {
 Vec pos,angles,origin,dir,delta;
 Vec *porigin=&origin,*pdir=&dir,*pdelta=&delta;
 void *rng=self->rng;
 factor *= func_005357F8(rng)*0x1.333332p-3f+0x1.999998p-5f;
 int ok=1;
 if(factor>0.5f) factor=0.5f;
 set(porigin,func_002E5E40(car,0.0f),func_002E5EA0(car,0.0f),func_002E5ED0(car,0.0f));
 func_00552A68(porigin,pdir);
 set(pdelta,func_002E5DC8(car),func_002E5DF0(car),func_002E5E18(car));
 func_00552C90(pdir,pdelta);
 float range=func_005357F8(rng)*30.0f+50.0f;
 func_00552A68(pdir,&pos);
 scale(&pos,factor*60.0f);
 func_00552C58(&pos,porigin);
 pos.X() += 2.0f*func_005357F8(rng)-1.0f;
 pos.Y() = origin.Y()+3.0f;
 pos.Z() += 2.0f*func_005357F8(rng)-1.0f;
 void *course=self->course;
 struct Query { Vec v; int id; } query;
 Vec hit;
 int id=-1;
 query.id=-1;
 query.v.x=pos.X(); query.v.y=pos.Y()+0.0f; query.v.z=pos.Z();
 Vec start,end;
 float height; Vec *pend;
 if(func_002F0858(path,6,0,&hit,func_0034B268(course,&query))<0 ||
    (set(&start,hit.x,hit.y,hit.z),pend=&end,id=func_003A7F60(course,&start),id<0) ||
    (func_003A9C38(course,&start,&pos,pend,&id,0.5f),id=-1,height=func_003A97E0(course,pend,&id),id<0)) ok=0;
 else { float h=height+0x1.999998p-4f; float *ey=&end.Y(); *ey=h+func_005357F8(rng)*0x1.333332p-1f; func_00552A68(pend,&pos); }
 func_00552A68(&pos,pdelta);
 func_00552C90(pdelta,porigin);
 float *ay=&angles.Y(),*ax=&angles.X(); *ay=func_005357F8(rng)*20.0f-15.0f;
 float a=func_003173F8(pdelta);
 *ax=a+func_005357F8(rng)*20.0f-10.0f;
 float *az=&angles.Z(); *az=func_005357F8(rng)*30.0f-15.0f;
 float len=func_00552A38(pdelta);
 __asm__("sqrt.s %0,%1":"=f"(len):"f"(len));
 self->distance=len; self->range=range;
 func_00552A68(&pos,(Vec *)((char *)self+0x190));
 func_0046E150();func_00473050();func_004751FC();
 func_00475780(angles.Z());func_00475730(angles.Y());func_00475758(angles.X());
 func_004755EC(-pos.x,-pos.y,-pos.z);func_004752F8((char *)self+0x100);func_004730A8();func_0046E1B0();
 return ok;
}
