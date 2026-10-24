/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_pair.h>
#define protected public
#define private public
#include <stl_list.h>
#include <stl_tree.h>
#undef protected
#undef private
extern "C" void *func_004A4690(int,int);
extern "C" void *func_004AE750(int,int);
extern "C" void *func_004F6678(void *,int,unsigned);
extern "C" void *exception__structor_0(unsigned);
template<class T> struct A {
 typedef unsigned size_type; typedef int difference_type;
 typedef T* pointer; typedef const T* const_pointer;
 typedef T& reference; typedef const T& const_reference; typedef T value_type;
 template<class U> struct rebind { typedef A<U> other; };
 A() throw() {} A(const A&) throw() {} template<class U> A(const A<U>&) throw() {}
 T *allocate(unsigned n,const void * =0) { return n ? (T*)func_004A4690(16,n*sizeof(T)) : 0; }
 void deallocate(T*,unsigned);
 void construct(T*p,const T&v) { new(p) T(v); }
 void destroy(T*p) { p->~T(); }
};
struct Item { short x,y; int z; char *p;
 static void *operator new(unsigned n) {return exception__structor_0(n);}
 Item(char *q):x(0),y(0),z(0),p(q) {}
};
struct Interface { virtual void f(); virtual unsigned query(); };
struct Less { unsigned char flag; Less():flag(0) {} bool operator()(int a,int b) const {return a<b;} };
typedef list<Item *,A<Item *> > List;
typedef pair<const int,Item *> Pair;
typedef _Rb_tree<int,Pair,_Select1st<Pair>,Less,A<Pair> > Tree;
struct Self { Interface *i; List l; Tree t; char *data; int a; unsigned shift; };
static inline void init_tree(Tree *t,const Less &comp) {
 t->_M_header=0; t->_M_header=t->_M_get_node();
 t->_M_node_count=0; t->_M_key_compare=comp; t->_M_empty_initialize();
}
extern "C" void func_004872F0(Self *s,Interface *i,int a,unsigned count,int stride) {
 List::iterator unused;
 s->i=i;
 List *l=&s->l; Tree *t=&s->t;
 l->_M_node=l->_M_get_node();
 l->_M_node->_M_next=l->_M_node; l->_M_node->_M_prev=l->_M_node;
 init_tree(t,Less());
 s->a=a; s->shift=0;
 unsigned base=i->query();
 for(unsigned j=0;j<32;j++) { if((base<<j)==(unsigned)stride) {s->shift=j;break;} }
 int size=stride*count;
 s->data=(char*)func_004AE750(64,size);
 func_004F6678(s->data,0,size);
 unsigned n=0;

 for(;n<count;n++) {
  l->push_back(new Item(s->data+n*stride));
 }
}
