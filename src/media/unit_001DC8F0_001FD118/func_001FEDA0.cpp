/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int pad; char *vt; };
struct Handle { Obj *p; char pad[12]; };
struct Node { Node *next,*prev; int value; };
struct List { int pad; Node *head; };
struct It { Node *node; char pad[12]; };
struct Entry { short delta,index; int (*fn)(void*); };
extern "C" int func_001FECA0(char*,Handle*) throw();
extern "C" void func_0022F240(Handle*,int);
extern "C" void func_002A7578(Handle*,Obj**);
static inline void start(It *it,List *l) { it->node=l->head; }
static inline void back(It *it) { it->node=it->node->prev; }
static inline int invoke(Obj *o) {
 Entry *e=(Entry*)(o->vt+0x1B0);
 return e->fn((char*)o+e->delta);
}
extern "C" void func_001FEDA0(char *p) {
 Handle h;
 It it;
 Obj *zero[4]; zero[0]=0;
 List *l=(List*)(p+24);
 func_002A7578(&h,zero);
 It *pit=&it;
 goto test;
 body:
  invoke(h.p);
  start(pit,l); back(pit);
  if(pit->node->value==0) goto done;
 test:
  if(func_001FECA0(p,&h)) goto body;
 done:
 func_0022F240(&h,2);
}
