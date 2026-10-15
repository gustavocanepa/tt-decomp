/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Flag { int v; };
extern volatile Flag D_00598670,D_00598674;
struct Port { int id; char state[0x3c]; int pending; char out[0x28]; };
extern char D_00777200[];
extern char D_00776F00[];
extern void *D_007772D8;
extern "C" void func_004BF548();
extern "C" void func_004BF340(void *) throw();
extern "C" void *func_004AF398(void *,void *);
extern "C" void func_004A59F0();
extern "C" void *func_004A53A0(void *);
extern "C" int func_004A5618(void *);
extern "C" void *func_004A58E0(unsigned int,int);
extern "C" int func_004DCFF0(int);
extern "C" int func_004DD098(void *,void *);
extern "C" void *func_004F6678(void *,int,unsigned int);
union Buffer { int words[8]; struct { void (*fn)(); int zero; } cb; };
extern "C" void func_004BF650() {
 Buffer b;
 if (D_00598670.v==0) {
  D_00598670.v=1;
  D_00598674.v=0;
  while (func_004DCFF0(0)!=1) func_004A59F0();
  char *base=D_00777200;
  char *buf=D_00776F00;
  for (int i=0,two=2,off=0; i<2; ++i,buf+=0x100,off+=0x6c) {
   Port *p=(Port *)(off+(int)base);
   func_004F6678(&b,0,0x20);
   b.words[0]=two;
   b.words[1]=i!=0;
   func_004F6678(p,0,0x6c);
   func_004BF340(p->state);
   while ((p->id=func_004DD098(&b,buf))<0) func_004A59F0();
  }
  D_00598674.v=1;
  b.cb.fn=func_004BF548;
  b.cb.zero=0;
  void *r=func_004AF398(&b,func_004A53A0(func_004A58E0(3,0)));
  D_007772D8=r;
  func_004A5618(r);
 }
}
