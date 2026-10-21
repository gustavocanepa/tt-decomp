/* compiler: ee-gcc2.96-no-strict-aliasing */
struct W { int x; char *vt; };
struct H { W *p; char pad[12]; };
struct Temp { int x; char pad[12]; };
struct E70 { short d,i; W **(*fn)(void *,int); };
struct E58 { short d,i; int (*fn)(void *); };
extern "C" void func_00281258(void *,int) throw();
extern "C" void func_002812B0(void *,void *) throw();
extern "C" int func_00283000(void *);
extern "C" int func_00283048(void *);
extern "C" void func_002830D0(void *,int,int);
extern "C" void func_002931C8(void *,int);
extern "C" void func_00293220(void *,void *);
extern "C" void *func_002944D0(void *,void *,void *);
extern "C" void func_00295180(void *);
extern "C" void func_0029CEF0(void *,int);
extern "C" void func_0029EA18(void *,int);
extern "C" void func_002A75A8(void *,int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
static inline int get(W *o,int i) {
 E70 *e=(E70 *)(o->vt+0x88);
 W *p=*e->fn((char *)o+e->d,i);
 E58 *f=(E58 *)(p->vt+0x68);
 return f->fn((char *)p+f->d);
}
extern "C" void func_00281780(H *out,void *arg1,int count,void *arg3) {
 H h;
 H a;
 if(count>0) {
  func_00293220(&h,arg3);
  H *pa=&a;
  func_002812B0(pa,arg1);
  W *p=pa->p;
  int lo=get(h.p,0);
  int hi=get(h.p,1);
  func_002830D0(p,lo,hi);
  func_00281258(pa,2);
  func_002931C8(&h,2);
  return;
 } else {
  H result;
  Temp t,v,w;
  func_002812B0(&h,arg1);
  H *pr=&result;
  func_00295180(pr);
  W *p=pr->p;
  Temp *pt=&t;
  int value=func_00283000(h.p);
  Temp *pv=&v;
  func_0029EA18(pv,value);
  func_002944D0(pt,p,pv);
  func_002A75A8(pt,2);
  func_0029CEF0(pv,2);
  W * p_2 = pr->p;
  value=func_00283048(h.p);
  Temp *pw=&w;
  func_0029EA18(pw,value);
  func_002944D0(pt,p_2,pw);
  func_002A75A8(pt,2);
  func_0029CEF0(pw,2);
  if(out!=pr) {
   W *q=pr->p;
   if(q) func_002C0FE8(q);
   if(out->p) func_002C1050(out->p);
   out->p=q;
  }
  func_002931C8(pr,2);
  func_00281258(&h,2);
 }
}
