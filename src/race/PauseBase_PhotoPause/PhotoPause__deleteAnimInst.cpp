/* compiler: ee-gcc2.96-stl */
extern "C" void free(void *) throw();
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
extern "C" void func_0043D510(void *);
extern "C" void func_0050E1A8(void *) throw();
struct Elem { int a,b,c; ~Elem() {} };
struct Rep { int len,cap,ref,sel; };
struct VE { short delta,index; void (*fn)(void *,int); };
struct Owner { char pad[0x5c]; VE *vt; };
struct Node { Owner *owner; Node *prev,*next; char pad[0x168-12]; char *str; int x,y; int val[2]; char *str2; vector<Elem> vec; int val2[2]; };
struct Obj { char pad[0x10]; Node *node; };
static inline void release(char *s) { Rep *r=(Rep *)(s-16); if (--r->ref==0) free(r); }
static inline void unlink(Node *p) {
 if(p->prev==p->next) { if(p->owner) { Owner *o=p->owner; VE *e=o->vt+1; e->fn((char *)o+e->delta,3); } }
 else { p->next->prev=p->prev; p->prev->next=p->next; }
}
extern "C" void PhotoPause__deleteAnimInst(Obj *self) {
 Node *p=self->node;
 if(p) {
  func_0043D510(p->val2);
  p->vec.~vector();
  release(p->str2);
  func_0043D510(p->val);
  release(p->str);
  unlink(p);
  func_0050E1A8(p);
  self->node=0;
 }
}
