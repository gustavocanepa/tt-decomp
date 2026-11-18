/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int state, status, mode; char b10[16]; int info; char b24[4]; int ready; char data[20]; };
struct Out { int len1; char src2[16]; int len0; char src1[16]; };
struct Port { int id; State state; int pending; Out out; };
struct Flag { int v; };
extern volatile Flag D_00598674;
extern char D_00776EC0[];
static inline int active(volatile Flag *const p) { return p->v; }
extern Port D_00777200[];
extern "C" void func_004BF340(State *) throw();
extern "C" void func_004BFB48();
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" int func_004DD1F8(int, void *);
extern "C" int func_004DD2D0(int, void *);
extern "C" unsigned char func_004DD3A0(int);
extern "C" int func_004DD8A8(int, void *);
extern "C" int func_004DD928(int, int, void *, int, void *);
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" int func_004FA6B0(int,int);
extern "C" int func_004FA710();
extern "C" void func_004BF358() {
 if (active(&D_00598674)) {
  func_004A4D68(D_00776EC0);
  int th=func_004FA710();
  int prev=func_004FA6B0(th,1);
  for (int i=0; i<2; ++i) {
   Port *p=&D_00777200[i];
   State *s=&p->state;
   Out *o=&p->out;
   int connected=func_004DD3A0(p->id);
   int state=s->state;
   if (connected==1) {
    switch(state) {
    case 0:
     s->info=func_004DD2D0(p->id,s->b24);
     s->mode=func_004DD8A8(p->id,s->b10);
     s->state=1;
     s->status=0;
     break;
    default: s->status=3; break;
    case 1: s->status=0; s->state=2; break;
    }
    s->ready=func_004DD1F8(p->id,s->data);
    if (p->pending && func_004DD928(p->id,o->len1,o->src2,o->len0,o->src1)==1) {
     if (--p->pending) func_004F6678(o->src1,0,o->len0);
    }
   } else {
    func_004BF340(s);
    p->pending=0;
   }
  }
  func_004FA6B0(th,prev);
  func_004A4DD8(D_00776EC0);
  func_004BFB48();
 }
}
