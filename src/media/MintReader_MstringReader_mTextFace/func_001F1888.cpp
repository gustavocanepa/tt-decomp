/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char pad[0x28]; int valid, value; };
struct Obj { char pad[0xDC]; int valid,value; };
struct Handle { Obj *p; char pad[12]; };
struct Tmp { void *p; char pad[12]; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct VObj { int data; VEntry *vtbl; };
extern "C" int func_001F0C00(Handle *,void *) throw();
extern "C" void func_001F0BA8(Handle *,int) throw();
extern "C" void func_0029CEF0(Tmp *,int);
extern "C" void func_0029EA18(Tmp *,int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
static inline void assign(Tmp *dst,Tmp *src) {
 if (dst != src) {
  void *p = src->p;
  if (p) func_002C0FE8(p);
  if (dst->p) func_002C1050(dst->p);
  dst->p = p;
 }
}
static inline int vcall(VObj *o) {
 VEntry *e = &o->vtbl[13];
 return e->fn((char *)o+e->delta);
}
extern "C" void func_001F1888(Tmp *dst,void *arg1,int n,VObj **reader) {
 Handle h;
 Tmp t;
 if (n == 0) {
  func_001F0C00(&h,arg1);
  Data *d = (Data *)((char *)h.p+0xB4);
  if (d->valid != 0) {
   func_0029EA18(&t,d->value);
   assign(dst,&t);
   func_0029CEF0(&t,2);
  } else {
   func_0029EA18(&t,-1);
   assign(dst,&t);
   func_0029CEF0(&t,2);
  }
  func_001F0BA8(&h,2);
 } else if (n == 1) {
  func_001F0C00(&h,arg1);
  int value = vcall(*reader);
  if (value >= 0) {
   h.p->valid = n;
   h.p->value = value;
  } else {
   h.p->valid = 0;
  }
  func_001F0BA8(&h,2);
 }
}
