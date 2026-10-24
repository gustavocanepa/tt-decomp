/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; int (*fn)(void *); };
struct Obj { int word; char *vt; };
struct Stack {
 int n; short pad4; unsigned short a[10]; unsigned short b[10]; char pad2e[2];
 float c[10]; float d[10]; void *h[4]; char data[0x600];
};
struct Out { int n; float v[512]; };
extern "C" void func_00128418(void *, int);
extern "C" void func_00128470(void *, void *);
extern "C" void *func_001324D8(void *);
extern "C" void func_001B3AE8(void *, int);
extern "C" void func_001B3DD8(void *, void *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void func_002EDD18(void *, void *, int);
extern "C" void *func_00408B58(void *);
extern "C" void func_00408D48(void *, void *);
extern "C" int func_0040D220(void *);
extern "C" void *func_004A45F8(int) throw();
extern "C" void func_001329D0(void **dst, void *arg1, int count, Obj **arg3) {
 Stack sp;
 void **h=sp.h;
 func_00128470(h, arg1);
 void *obj=func_001324D8(h[0]);
 func_00128418(h,2);
 obj=func_00408B58(obj);
 if (func_0040D220(obj)) {
  func_00408D48(obj, sp.data);
  if(count>0) { Obj *o=*arg3; VEntry *e=(VEntry *)(o->vt+0x68); sp.data[0x156]=e->fn((char *)o+e->delta); }
  func_002EDD18(sp.data,&sp,0);
  Out *out=(Out *)func_004A45F8(0x804);
  float scale=100.0f; float max=1.0f;
 int initial=sp.n;
  if(initial>0) { unsigned short *p=sp.b; int n=initial; do {float x=*p++; if(max<x) max=x;} while(--n); }
  out->n=initial*2;
  if(initial>0) {
   int n=sp.n; unsigned short *b=sp.b; float *d=sp.d; unsigned short *a=sp.a; float *c=sp.c; char *v=(char *)out;
   do { float x=*a++; float y=*b++; float g=*c/scale; float f=*d; --n; ++d; ++c;
    *(float *)(v+4)=g; *(float *)(v+8)=x/max; *(float *)(v+12)=f/scale; *(float *)(v+16)=y/max; v+=16;
   } while(n);
  }
  func_001B3DD8(h,out,1);
  if(dst!=h) { void *p=h[0]; if(p)func_002C0FE8(p); if(*dst)func_002C1050(*dst); *dst=p; }
  func_001B3AE8(h,2);
 }
}
