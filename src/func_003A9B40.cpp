/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V3 { float x,y,z; };
struct S { V3 v,a; int flag; V3 b; float t; };
extern "C" void func_00552A68(float *,float *);
extern "C" void func_0034B6B8(void *,void *,float,float,float,float,void *,int);
extern "C" void func_003A9B08();
extern "C" int func_003A9B40(void *self,float *p,float *q,float *dest,float *out,int *id) {
 S s;
 float zero = 0.0f;
 *out=zero;
 func_00552A68(q,dest);
 float *pa=&s.a.x;
 s.flag=0;
 s.t=zero;
 float *pb=&s.b.x;
 func_00552A68(p,&s.v.x);
 func_00552A68(q,pa);
 func_0034B6B8(self,(void *)func_003A9B08,zero,zero,zero,zero,&s,*id);
 if(s.flag) {
 func_00552A68(pb,dest);
 *out=s.t;
 return 1;
 }
 return 0;
}
