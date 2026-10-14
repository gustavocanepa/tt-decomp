/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { void *p; char pad[12]; };
struct Floats { float a,b; char pad[8]; };
extern "C" void func_001F0C00(Handle *,void *) throw();
extern "C" void func_001F0BA8(Handle *,int) throw();
extern "C" void func_001F2768(void *,float *,float *);
extern "C" void func_00295180(Handle *);
extern "C" void func_0029B380(Handle *,float);
extern "C" Handle *func_002944D0(Handle *,void *,Handle *);
extern "C" void func_002A75A8(Handle *,int);
extern "C" void func_00299AB0(Handle *,int);
extern "C" void func_002931C8(Handle *,int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void MTextFace__getTextSize(Handle *dst,void *arg1) {
 Handle h;
 Floats f;
 Handle res,ret,x,y;
 Handle *pr,*pt;
 void *p;
 func_001F0C00(&h,arg1);
 func_001F2768(h.p,&f.a,&f.b);
 pr = &res;
 func_00295180(pr);
 p = pr->p;
 {
 Handle *pf = &x;
 pt = &ret;
 func_0029B380(pf,f.a);
 func_002944D0(pt,p,pf);
 func_002A75A8(pt,2);
 func_00299AB0(pf,2);
 }
 p = pr->p;
 {
 Handle *pf = &y;
 func_0029B380(pf,f.b);
 func_002944D0(pt,p,pf);
 func_002A75A8(pt,2);
 func_00299AB0(pf,2);
 }
 if (dst != pr) {
  void *q = pr->p;
  if (q) func_002C0FE8(q);
  if (dst->p) func_002C1050(dst->p);
  dst->p = q;
 }
 func_002931C8(pr,2);
 func_001F0BA8(&h,2);
}
